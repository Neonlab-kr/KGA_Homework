#include "Stdafx.h"
#include <cmath>

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("Windows API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void DrawCircle(HDC hdc, double cx, double cy, double r, COLORREF rgb);

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

    switch (iMessage)
    {
    case WM_CREATE:
        break;

    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);

        DrawCircle(hdc,400,400,300,RGB(255,0,0));
        DrawCircle(hdc,400,400,280,RGB(255,0,0));

        POINT points[5] = { PointMake(399,120),PointMake(666,312),PointMake(565,625),PointMake(236,627),PointMake(133,314) };
        POINT points2[5] = { PointMake(298,433),PointMake(400,506),PointMake(502,432),PointMake(462,313),PointMake(336,313) };

        //오각형
        MoveToEx(hdc, points[4].x, points[4].y, NULL);
        for (int i = 0; i < 5; i++)
        {
	        LineTo(hdc, points[i].x, points[i].y);
        }

        //외부 별
        MoveToEx(hdc, points[4].x, points[4].y, NULL);
        LineTo(hdc, points[1].x, points[1].y);
        LineTo(hdc, points[3].x, points[3].y);
        LineTo(hdc, points[0].x, points[0].y);
        LineTo(hdc, points[2].x, points[2].y);
        LineTo(hdc, points[4].x, points[4].y);

        //내부 별
        MoveToEx(hdc, points2[4].x, points2[4].y, NULL);
        LineTo(hdc, points2[1].x, points2[1].y);
        LineTo(hdc, points2[3].x, points2[3].y);
        LineTo(hdc, points2[0].x, points2[0].y);
        LineTo(hdc, points2[2].x, points2[2].y);
        LineTo(hdc, points2[4].x, points2[4].y);

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_LBUTTONDOWN:
        break;

    case WM_RBUTTONDOWN:
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

void DrawCircle(HDC hdc, double cx, double cy, double r, COLORREF rgb)
{
    for (double y = cy-r; y <= cy+r; y += 0.01)
    {
        double temp = sqrt(r * r - (y - cy) * (y - cy));
        SetPixel(hdc, cx - temp, y, rgb);
        SetPixel(hdc, cx + temp, y, rgb);
    }
}