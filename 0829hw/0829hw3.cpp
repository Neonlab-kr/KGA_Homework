#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("Windows API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

RECT rc[2];
RECT innerRc;
bool control = false;

static const int wMax = 784;
static const int hMax = 761;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
    _hInstance = hInstance;

    WNDCLASS wndClass;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hInstance = hInstance;
    wndClass.lpfnWndProc = (WNDPROC)WndProc;
    wndClass.lpszClassName = _lpszClass;
    wndClass.lpszMenuName = NULL;
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClass(&wndClass);
    _hWnd = CreateWindow(_lpszClass, _lpszClass, WS_OVERLAPPEDWINDOW, 400, 100, 800, 800, NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(_hWnd, nCmdShow);

    MSG message;
    while (GetMessage(&message, 0, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    int speed = 10;

    switch (iMessage)
    {
    case WM_CREATE:
        rc[0] = RectMakeCenter(wMax / 4, hMax / 4, 100, 100);
        rc[1] = RectMakeCenter(wMax / 2, hMax / 2, 100, 100);
        innerRc = RectMakeCenter(wMax / 4, hMax / 4, 50, 50);
        control = false;
        break;

    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);

        DrawRectMake(hdc, rc[0]);
        DrawRectMake(hdc, rc[1]);
        DrawRectMake(hdc, innerRc);

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_RBUTTONDOWN:
        rc[0] = RectMakeCenter(wMax / 4, hMax / 4, 100, 100);
        rc[1] = RectMakeCenter(wMax / 2, hMax / 2, 100, 100);
        innerRc = RectMakeCenter(wMax / 4, hMax / 4, 50, 50);
        control = false;
        InvalidateRect(hWnd, NULL, true);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_UP:
        {
            int moveDis;
            bool isCollide = rc[control].right > rc[!control].left && rc[control].bottom > rc[!control].top && (rc[control].top - speed) < rc[!control].bottom && rc[control].left < rc[!control].right;
            if (rc[control].top == 0 || (isCollide && (rc[!control].top == 0)))
            {
                break;
            }
            hdc = GetDC(hWnd);
            if (isCollide)
            {
                moveDis = rc[!control].bottom - (rc[control].top - speed);
                if (rc[!control].top - moveDis < 0) moveDis = rc[!control].top;
                rc[!control].top -= moveDis;
                rc[!control].bottom -= moveDis;
                moveDis = rc[control].top - rc[!control].bottom;
                rc[control].top -= moveDis;
                rc[control].bottom -= moveDis;
                control = !control;
                innerRc = RectMakeCenter((rc[control].left + rc[control].right) / 2, (rc[control].top + rc[control].bottom) / 2, 50, 50);
            }
            else
            {
                moveDis = speed;
                if (rc[control].top - moveDis < 0) moveDis = rc[control].top;
                rc[control].top -= moveDis;
                rc[control].bottom -= moveDis;

                moveDis = innerRc.bottom - rc[control].bottom;
                if (moveDis < 0) moveDis = 0;
                innerRc.top -= moveDis;
                innerRc.bottom -= moveDis;
            }
            
            InvalidateRect(hWnd, NULL, true);
            ReleaseDC(hWnd, hdc);
        }
        break;

        case VK_DOWN:
        {
            int moveDis;
            bool isCollide = rc[control].right > rc[!control].left && (rc[control].bottom + speed) > rc[!control].top && rc[control].top < rc[!control].bottom && rc[control].left < rc[!control].right;
            if (rc[control].bottom == hMax || (isCollide && (rc[!control].bottom == hMax)))
            {
                break;
            }
            hdc = GetDC(hWnd);
            if (isCollide)
            {
                moveDis = (rc[control].bottom + speed) - rc[!control].top;
                if (rc[!control].bottom + moveDis > hMax) moveDis = hMax - rc[!control].bottom;
                rc[!control].bottom += moveDis;
                rc[!control].top += moveDis;
                moveDis = rc[!control].top - rc[control].bottom;
                rc[control].top += moveDis;
                rc[control].bottom += moveDis;
                control = !control;
                innerRc = RectMakeCenter((rc[control].left + rc[control].right) / 2, (rc[control].top + rc[control].bottom) / 2, 50, 50);
            }
            else
            {
                moveDis = speed;
                if (rc[control].bottom + moveDis > hMax) moveDis = hMax - rc[control].bottom;
                rc[control].top += moveDis;
                rc[control].bottom += moveDis;

                moveDis = innerRc.top - rc[control].top;
                if (moveDis > 0) moveDis = 0;
                innerRc.top -= moveDis;
                innerRc.bottom -= moveDis;

            }

            InvalidateRect(hWnd, NULL, true);
            ReleaseDC(hWnd, hdc);
        }
        break;

        case VK_LEFT:
        {
            int moveDis;
            bool isCollide = rc[control].right > rc[!control].left && rc[control].bottom > rc[!control].top && rc[control].top < rc[!control].bottom && (rc[control].left - speed) < rc[!control].right;
            if (rc[control].left == 0 || (isCollide && (rc[!control].left == 0)))
            {
                break;
            }
            hdc = GetDC(hWnd);
            if (isCollide)
            {
                int moveDis = rc[!control].right - (rc[control].left - speed);
                if (rc[!control].left - moveDis < 0) moveDis = rc[!control].left;
                rc[!control].left -= moveDis;
                rc[!control].right -= moveDis;
                moveDis = rc[control].left - rc[!control].right;
                rc[control].left -= moveDis;
                rc[control].right -= moveDis;
                control = !control;
                innerRc = RectMakeCenter((rc[control].left + rc[control].right) / 2, (rc[control].top + rc[control].bottom) / 2, 50, 50);
            }
            else
            {
                moveDis = speed;
                if (rc[control].left - moveDis < 0) moveDis = rc[control].left;
                rc[control].left -= moveDis;
                rc[control].right -= moveDis;

                moveDis = innerRc.right - rc[control].right;
                if (moveDis < 0) moveDis = 0;
                innerRc.left -= moveDis;
                innerRc.right -= moveDis;
            }

            InvalidateRect(hWnd, NULL, true);
            ReleaseDC(hWnd, hdc);
        }
        break;

        case VK_RIGHT:
        {
            int moveDis;
            bool isCollide =
                (rc[control].right + speed) > rc[!control].left && rc[control].bottom > rc[!control].top && rc[control].top < rc[!control].bottom && rc[control].left < rc[!control].right;
            if (rc[control].right == wMax || (isCollide && (rc[!control].right == wMax)))
            {
                break;
            }
            hdc = GetDC(hWnd);
            if (isCollide)
            {
                moveDis = (rc[control].right + speed) - rc[!control].left;
                if (rc[!control].right + moveDis > wMax) moveDis = wMax - rc[!control].right;
                rc[!control].right += moveDis;
                rc[!control].left += moveDis;
                moveDis = rc[!control].left - rc[control].right;
                rc[control].left += moveDis;
                rc[control].right += moveDis;
                control = !control;
                innerRc = RectMakeCenter((rc[control].left + rc[control].right) / 2, (rc[control].top + rc[control].bottom) / 2, 50, 50);
            }
            else
            {
                moveDis = speed;
                if (rc[control].right + moveDis > wMax) moveDis = wMax - rc[control].right;
                rc[control].left += moveDis;
                rc[control].right += moveDis;

                moveDis = innerRc.left - rc[control].left;
                if (moveDis > 0) moveDis = 0;
                innerRc.left -= moveDis;
                innerRc.right -= moveDis;
            }

            InvalidateRect(hWnd, NULL, true);
            ReleaseDC(hWnd, hdc);
        }
        break;

        case VK_ESCAPE:
            PostMessage(hWnd, WM_DESTROY, 0, 0);
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}