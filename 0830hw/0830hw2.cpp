//과제2.마우스로 무작위 도형 출력
//- 마우스로 클릭한 좌표에 무작위 도형을 출력한다.
//- 도형의 크기, 모양, 종류 모두 무작위로 설정
//- 도형의 종류는 사각형 / 원 / 삼각형 / 다각형
//
//- 삼각형 / 다각형->Polygon()

#include "Stdafx.h"
#include <algorithm>

//전역변수
HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0,0 };

//함수
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

void PolygonMakeCenter(HDC hdc, LONG x, LONG y, int angleCount);
void printTriangle(HDC hdc, LONG x, LONG y);
void printRandomShape(HDC hdc, LONG x, LONG y);

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
    static POINT pt = { 0,0 };

    switch (iMessage)
    {
    case WM_CREATE:
        break;

    case WM_PAINT:
        break;

    case WM_MOUSEMOVE:
        pt.x = LOWORD(lParam);
        pt.y = HIWORD(lParam);
        break;

    case WM_LBUTTONDOWN:
        hdc = GetDC(hWnd);
        printRandomShape(hdc, pt.x, pt.y);
        ReleaseDC(hWnd, hdc);
        break;

    case WM_RBUTTONDOWN:
        InvalidateRect(hWnd, NULL, true);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            break;
        case VK_RIGHT:
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

void printRandomShape(HDC hdc, LONG x, LONG y)
{
    int sel = RND->getInt(4);
    switch (sel)
    {
    case 0:
        DrawRectMake(hdc, RectMakeCenter(x, y, RND->getInt(WINSIZE_X-x > x ? 2*x : 2*(WINSIZE_X - x)), RND->getInt(WINSIZE_Y - y > y ? 2 * y : 2 * (WINSIZE_Y - y))));
        break;
    case 1:
        EllipseMakeCenter(hdc, x, y, RND->getInt(WINSIZE_X - x > x ? 2 * x : 2 * (WINSIZE_X - x)), RND->getInt(WINSIZE_Y - y > y ? 2 * y : 2 * (WINSIZE_Y - y)));
        break;
    case 2:
        printTriangle(hdc, x, y);
        break;
    case 3:
        PolygonMakeCenter(hdc, x, y, RND->getFromTo(5, 10));
        break;
    }
}

void PolygonMakeCenter(HDC hdc, LONG x, LONG y, int angleCount)
{
    POINT* points = new POINT[angleCount * 2];

    int r = RND->getInt((((((x < (WINSIZE_X - x)) ? x : (WINSIZE_X - x))) < (((y < (WINSIZE_Y - y)) ? y : (WINSIZE_Y - y)))) ? (((x < (WINSIZE_X - x)) ? x : (WINSIZE_X - x))) : (((y < (WINSIZE_Y - y)) ? y : (WINSIZE_Y - y)))));
    int angInc = 360 / angleCount;
    int randStartAngle = RND->getFromTo(0, 360);
    int randEndAngle = randStartAngle + 360;
    int angle = randStartAngle;
    for (int i = 0; i < angleCount; i++)
    {
        angle += angInc;
        LONG px = x + r * cos(angle * 3.14 / 180.0);
        LONG py = y + r * sin(angle * 3.14 / 180.0);

        points[i] = { px, py };
    }

    Polygon(hdc, points, angleCount);
    SAFE_DELETE_ARRAY(points);
}

void printTriangle(HDC hdc, LONG x, LONG y)
{
    POINT points[3];

    do
    {
        points[0] = { RND->getInt(WINSIZE_X),RND->getInt(WINSIZE_Y) };
        points[1] = { RND->getInt(WINSIZE_X),RND->getInt(WINSIZE_Y) };
        points[2] = { 3 * x - points[0].x - points[1].x , 3 * y - points[0].y - points[1].y };
    } while (points[2].x < 0 || points[2].x > WINSIZE_X || points[2].y < 0 || points[2].y > WINSIZE_Y);

    Polygon(hdc, points, 3);
}
