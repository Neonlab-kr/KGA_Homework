#include "Stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("Windows API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

RECT rc1, rc2;

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

    int speed = 20;

    switch (iMessage)
    {
    case WM_CREATE:
        rc1 = RectMakeCenter(wMax / 4, hMax / 4, 100, 100);
        rc2 = RectMakeCenter(wMax / 2, hMax / 2, 100, 100);
        break;

    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);

        DrawRectMake(hdc, rc1);
        DrawRectMake(hdc, rc2);

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_RBUTTONDOWN:
        rc1 = RectMakeCenter(wMax / 4, hMax / 4, 100, 100);
        rc2 = RectMakeCenter(wMax / 2, hMax / 2, 100, 100);
        InvalidateRect(hWnd, NULL, true);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_UP:
        {
            int moveDis;
            bool isCollide = rc1.right > rc2.left && rc1.bottom > rc2.top && (rc1.top - speed) < rc2.bottom && rc1.left < rc2.right;
            if (rc1.top == 0 || (isCollide && (rc2.top == 0)))
            {
                break;
            }
            hdc = GetDC(hWnd);
            InvalidateRect(hWnd, &rc1, true);
            if (isCollide)
            {
                InvalidateRect(hWnd, &rc2, true);
                moveDis = rc2.bottom - (rc1.top - speed);
                if (rc2.top - moveDis < 0) moveDis = rc2.top;
                rc2.top -= moveDis;
                rc2.bottom -= moveDis;
                DrawRectMake(hdc, rc2);
                moveDis = rc1.top - rc2.bottom;
                rc1.top -= moveDis;
                rc1.bottom -= moveDis;
            }
            else
            {
                moveDis = speed;
                if (rc1.top - moveDis < 0) moveDis = rc1.top;
                rc1.top -= moveDis;
                rc1.bottom -= moveDis;
            }
            DrawRectMake(hdc, rc1);
            ReleaseDC(hWnd, hdc);
        }
            break;

        case VK_DOWN:
        {
            int moveDis;
            bool isCollide = rc1.right > rc2.left && (rc1.bottom + speed) > rc2.top && rc1.top < rc2.bottom && rc1.left < rc2.right;
            if (rc1.bottom == hMax || (isCollide && (rc2.bottom == hMax)))
            {
                break;
            }
            hdc = GetDC(hWnd);
            InvalidateRect(hWnd, &rc1, true);
            if (isCollide)
            {
                InvalidateRect(hWnd, &rc2, true);
                moveDis = (rc1.bottom + speed) - rc2.top;
                if (rc2.bottom + moveDis > hMax) moveDis = hMax - rc2.bottom;
                rc2.bottom += moveDis;
                rc2.top += moveDis;
                DrawRectMake(hdc, rc2);
                moveDis = rc2.top - rc1.bottom;
                rc1.top += moveDis;
                rc1.bottom += moveDis;
            }
            else
            {
                moveDis = speed;
                if (rc1.bottom + moveDis > hMax) moveDis = hMax - rc1.bottom;
                rc1.top += moveDis;
                rc1.bottom += moveDis;
            }
            DrawRectMake(hdc, rc1);
            ReleaseDC(hWnd, hdc);
        }
            break;

        case VK_LEFT:
        {
            int moveDis;
            bool isCollide = rc1.right > rc2.left && rc1.bottom > rc2.top && rc1.top < rc2.bottom && (rc1.left - speed) < rc2.right;
            if (rc1.left == 0 || (isCollide && (rc2.left == 0)))
            {
                break;
            }
            hdc = GetDC(hWnd);
            InvalidateRect(hWnd, &rc1, true);
            if (isCollide)
            {
                InvalidateRect(hWnd, &rc2, true);
                int moveDis = rc2.right - (rc1.left - speed);
                if (rc2.left - moveDis < 0) moveDis = rc2.left;
                rc2.left -= moveDis;
                rc2.right -= moveDis;
                DrawRectMake(hdc, rc2);
                moveDis = rc1.left - rc2.right;
                rc1.left -= moveDis;
                rc1.right -= moveDis;
            }
            else
            {
                moveDis = speed;
                if (rc1.left - moveDis < 0) moveDis = rc1.left;
                rc1.left -= moveDis;
                rc1.right -= moveDis;
            }
            DrawRectMake(hdc, rc1);
            ReleaseDC(hWnd, hdc);
        }
            break;

        case VK_RIGHT:
        {
            int moveDis;
            bool isCollide =
                (rc1.right + speed) > rc2.left && rc1.bottom > rc2.top && rc1.top < rc2.bottom && rc1.left < rc2.right;
            if (rc1.right == wMax || (isCollide && (rc2.right == wMax)))
            {
                break;
            }
            hdc = GetDC(hWnd);
            InvalidateRect(hWnd, &rc1, true);
            if (isCollide)
            {
                InvalidateRect(hWnd, &rc2, true);
                moveDis = (rc1.right + speed) - rc2.left;
                if (rc2.right + moveDis > wMax) moveDis = wMax - rc2.right;
                rc2.right += moveDis;
                rc2.left += moveDis;
                DrawRectMake(hdc, rc2);
                moveDis = rc2.left - rc1.right;
                rc1.left += moveDis;
                rc1.right += moveDis;
            }
            else
            {
                moveDis = speed;
                if (rc1.right + moveDis > wMax) moveDis = wMax - rc1.right;
                rc1.left += moveDis;
                rc1.right += moveDis;
            }
            DrawRectMake(hdc, rc1);
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