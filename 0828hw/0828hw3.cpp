#include <Windows.h>
#include <tchar.h>
#include <cmath>

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("Windows API");

void myDraw(HDC hdc, LONG left, LONG top, LONG right, LONG bottom, double startY, double endY, COLORREF rgb);
void DrawLeaf(HDC hdc);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
    _hInstance = hInstance;

    WNDCLASS wndClass;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
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

    MSG messsage;
    while (GetMessage(&messsage, 0, 0, 0))
    {
        TranslateMessage(&messsage);
        DispatchMessage(&messsage);
    }
    return messsage.wParam;
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
        hdc = BeginPaint(hWnd, &ps);

        //ÀÙ
        DrawLeaf(hdc);

        //ÁÂ»ó´Ü
        myDraw(hdc, 201, 198, 408, 402, 198, 250, RGB(96, 187, 68));

        //¿ì»ó´Ü
        myDraw(hdc, 358, 198, 558, 402, 198, 250, RGB(96, 187, 68));

        //°¡Àå Å« ¿ø
        myDraw(hdc, 136, 184, 625, 666, 214, 284, RGB(96, 187, 68));
        myDraw(hdc, 136, 184, 625, 666, 284, 354, RGB(252, 194, 39));
        myDraw(hdc, 136, 184, 625, 666, 354, 424, RGB(246, 130, 31));
        myDraw(hdc, 136, 184, 625, 666, 424, 494, RGB(224, 58, 60));
        myDraw(hdc, 136, 184, 625, 666, 494, 564, RGB(149, 61, 148));
        myDraw(hdc, 136, 184, 625, 666, 564, 636, RGB(0, 158, 221));

        //ÁÂÇÏ´Ü
        myDraw(hdc, 207, 447, 410, 652, 590, 652, RGB(0, 158, 221));

        //¿ìÇÏ´Ü
        myDraw(hdc, 348, 447, 553, 652, 590, 652, RGB(0, 158, 221));

        //º£¾î¸ÔÈù ºÎºÐ
        myDraw(hdc, 486, 276, 714, 496, 276, 496, RGB(255, 255, 255));

        EndPaint(hWnd, &ps);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostMessage(hWnd, WM_DESTROY, 0, 0);
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

void myDraw(HDC hdc, LONG left, LONG top, LONG right, LONG bottom, double startY, double endY, COLORREF rgb)
{
    int cx = (left + right) / 2;
    int cy = (top + bottom) / 2;
    int r = ((right - left) >= (bottom - top) ? (bottom - top) : (right - left)) / 2;

    for (int y = startY; y <= endY; y++)
    {
        int startX = cx - sqrt(r * r - (y - cy) * (y - cy));
        int endX = cx + sqrt(r * r - (y - cy) * (y - cy));
        for (int x = startX; x < endX; x++)
        {
            SetPixel(hdc, x, y, rgb);
        }
    }
}

void DrawLeaf(HDC hdc)
{
    int cx1 = 337;
    int cy1 = -50;
    int cx2 = 570;
    int cy2 = 283;
    int r = 230;

    for (int y = 50; y < 200; ++y) {
        for (int x = 300; x < 550; ++x) {
            if (((x - cx1) * (x - cx1) + (y - cy1) * (y - cy1) <= r * r) && ((x - cx2) * (x - cx2) + (y - cy2) * (y - cy2) <= r * r)) {
                SetPixel(hdc, x, y, RGB(96, 187, 68));
            }
        }
    }
}