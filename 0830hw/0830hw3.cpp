//과제3.내 얼굴 그려오기(다음주 화요일까지)
//
//- 도형을 통해 과제를 해올 것
//- 쓸수 있는건 다써봐

#include "Stdafx.h"

//전역변수
HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0,0 };
const RECT pointPrintArea = { 0,0,120,23 };

//함수
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

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
    wndClass.lpszClassName = WINNAME;
    wndClass.lpszMenuName = NULL;
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClass(&wndClass);
    _hWnd = CreateWindow(WINNAME, WINNAME, WINSTYLE, WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y, NULL, (HMENU)NULL, hInstance, NULL);
    setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);
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

    static POINT pt = { 0,0 };
    char strPT[128];

    switch (iMessage)
    {
    case WM_CREATE:
        break;

    case WM_PAINT:
    {
        POINT BezierLine[16];
        hdc = BeginPaint(hWnd, &ps);

        wsprintf(strPT, "X: %d       Y: %d", pt.x, pt.y);
        TextOut(hdc, 10, 10, strPT, strlen(strPT));

        Arc(hdc, 200, 100, 600, 600, 230, 200, 570, 200);

        EllipseMake(hdc, 220, 250, 170, 170);
        EllipseMake(hdc, 410, 250, 170, 170);
        Arc(hdc, 390, 345, 410, 325, 410, 325, 390, 325);
        BezierLine[0] = { 385,290 };

        BezierLine[1] = { 390,380 };
        BezierLine[2] = { 350,390 };
        BezierLine[3] = { 355,420 };

        BezierLine[4] = { 365,430 };
        BezierLine[5] = { 370,405 };
        BezierLine[6] = { 390,420 };

        BezierLine[7] = { 397,425 };
        BezierLine[8] = { 404,425 };
        BezierLine[9] = { 410,420 };

        BezierLine[10] = { 430,405 };
        BezierLine[11] = { 435,430 };
        BezierLine[12] = { 445,420 };

        BezierLine[13] = { 450,390 };
        BezierLine[14] = { 410,380 };
        BezierLine[15] = { 415,290 };
        PolyBezier(hdc, BezierLine, 16);

        MoveToEx(hdc, 350, 500, NULL);
        LineTo(hdc, 450, 500);

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_MOUSEMOVE:
        pt.x = LOWORD(lParam);
        pt.y = HIWORD(lParam);

        InvalidateRect(hWnd, &pointPrintArea, true);
        break;

    case WM_LBUTTONDOWN:
        break;

    case WM_RBUTTONDOWN:
        break;

    case WM_RBUTTONUP:
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case 'R':
            InvalidateRect(hWnd, NULL, true);
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

void setWindowSize(int x, int y, int width, int height)
{
    RECT rc = { 0,0,width,height };
    AdjustWindowRect(&rc, WINSTYLE, false);
    SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}
