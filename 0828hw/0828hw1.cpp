#include <Windows.h>
#include <tchar.h>
#include <cmath>

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("Windows API");

void myDraw(HDC, LONG left, LONG top, LONG right, LONG bottom, double startAngle, double endAngle, double dotCount);
void DrawFirstName(HDC);
void DrawSecondName(HDC);
void DrawUnrealEngine(HDC);

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
    static int count = 0;

    RECT firstNameArea = { 0,0,392,392 };
    RECT secondNameArea = { 392,0,785,392 };

    switch (iMessage)
    {
    case WM_CREATE:
        break;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        DrawUnrealEngine(hdc);
        EndPaint(hWnd, &ps);
        break;
    case WM_LBUTTONDOWN:
        switch (count)
        {
        case 0:
            hdc = GetDC(hWnd);
            DrawFirstName(hdc);
            ReleaseDC(hWnd, hdc);
            count++;
            break;

        case 1:
            hdc = GetDC(hWnd);
            DrawSecondName(hdc);
            ReleaseDC(hWnd, hdc);
            count++;
            break;

        default:
            break;
        }
        break;

    case WM_RBUTTONDOWN:
        switch (count)
        {
        case 1:
            InvalidateRect(hWnd, &firstNameArea, true);
            count--;
            break;
        case 2:
            InvalidateRect(hWnd, &secondNameArea, true);
            count--;
            break;
        default:
            break;
        }
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
    return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

void myDraw(HDC hdc, LONG left, LONG top, LONG right, LONG bottom, double startAngle, double endAngle, double dotCount)
{
    int cx = (left + right) / 2;
    int cy = (top + bottom) / 2;
    int r = ((right - left) >= (bottom - top) ? (bottom - top) : (right - left)) / 2;

    if (endAngle < startAngle)
    {
        int temp = startAngle;
        startAngle = endAngle;
        endAngle = temp;
    }

    double angInc = (endAngle - startAngle) / dotCount;
    MoveToEx(hdc, cx + r * cos(startAngle * 3.14 / 180.0), cy + r * sin(startAngle * 3.14 / 180.0), NULL);

    for (double angle = startAngle; angle <= endAngle; angle += angInc)
    {
        int x = cx + r * cos(angle * 3.14 / 180.0);
        int y = cy + r * sin(angle * 3.14 / 180.0);

        LineTo(hdc, x, y);
    }
}

void DrawFirstName(HDC hdc)
{
    //ぁ
    MoveToEx(hdc, 72, 86, NULL);
    LineTo(hdc, 180, 88);
    LineTo(hdc, 92, 184);

    //び
    MoveToEx(hdc, 241, 73, NULL);
    LineTo(hdc, 241, 191);

    //け
    MoveToEx(hdc, 110, 229, NULL);
    LineTo(hdc, 110, 336);
    LineTo(hdc, 237, 336);
    LineTo(hdc, 237, 229);
    LineTo(hdc, 110, 229);
}

void DrawSecondName(HDC hdc)
{
    //し
    myDraw(hdc, 515, 81, 595, 149, 0, 360, 360);

    //ぬ
    MoveToEx(hdc, 392 + 95, 185, NULL);
    LineTo(hdc, 392 + 239, 185);
    MoveToEx(hdc, 392 + 164, 185, NULL);
    LineTo(hdc, 392 + 164, 241);

    //っ
    MoveToEx(hdc, 392 + 218, 203, NULL);
    LineTo(hdc, 392 + 274, 203);
    MoveToEx(hdc, 392 + 274, 74, NULL);
    LineTo(hdc, 392 + 274, 247);

    //い
    MoveToEx(hdc, 392 + 120, 241, NULL);
    LineTo(hdc, 392 + 120, 319);
    LineTo(hdc, 392 + 258, 319);
}

void DrawUnrealEngine(HDC hdc)
{
    MoveToEx(hdc, 0, 392, NULL);
    LineTo(hdc, 785, 392);

    //U
    MoveToEx(hdc, 242, 46 + 392, NULL);
    LineTo(hdc, 242, 112 + 392);
    myDraw(hdc, 203, 77 + 392, 243, 144 + 392, 0, 180, 180);
    LineTo(hdc, 203, 46 + 392);

    //n
    MoveToEx(hdc, 267, 89 + 392, NULL);
    LineTo(hdc, 267, 130 + 392);
    myDraw(hdc, 259, 96 + 392, 300, 120 + 392, 180, 360, 180);
    LineTo(hdc, 290, 130 + 392);

    //r
    MoveToEx(hdc, 315, 83 + 392, NULL);
    LineTo(hdc, 315, 130 + 392);
    MoveToEx(hdc, 315, 108 + 392, NULL);
    myDraw(hdc, 290, 88 + 392, 374, 120 + 392, 180, 360, 180);

    //e
    myDraw(hdc, 363, 80 + 392, 414, 135 + 392, 40, 360, 320);
    LineTo(hdc, 363, 106 + 392);

    //a
    myDraw(hdc, 437, 88 + 392, 477, 132 + 392, 0, 360, 360);
    LineTo(hdc, 485, 130 + 392);

    //l
    MoveToEx(hdc, 520, 69 + 392, NULL);
    LineTo(hdc, 520, 128 + 392);

    //E
    MoveToEx(hdc, 252, 226 + 392, NULL);
    LineTo(hdc, 197, 226 + 392);
    LineTo(hdc, 197, 317 + 392);
    LineTo(hdc, 252, 317 + 392);
    MoveToEx(hdc, 197, 271 + 392, NULL);
    LineTo(hdc, 252, 271 + 392);

    //n
    MoveToEx(hdc, 267, 279 + 392, NULL);
    LineTo(hdc, 267, 320 + 392);
    myDraw(hdc, 259, 286 + 392, 300, 310 + 392, 180, 360, 180);
    LineTo(hdc, 290, 320 + 392);

    //g
    myDraw(hdc, 305, 277 + 392, 356, 310 + 392, 0, 360, 360);
    LineTo(hdc, 345, 320 + 392);
    myDraw(hdc, 305, 305 + 392, 356, 336 + 392, 0, 180, 180);

    //i
    MoveToEx(hdc, 370, 269 + 392, NULL);
    LineTo(hdc, 370, 272 + 392);
    MoveToEx(hdc, 370, 279 + 392, NULL);
    LineTo(hdc, 370, 320 + 392);

    //n
    MoveToEx(hdc, 390, 279 + 392, NULL);
    LineTo(hdc, 390, 320 + 392);
    myDraw(hdc, 390, 286 + 392, 413, 310 + 392, 180, 360, 180);
    LineTo(hdc, 411, 320 + 392);
    
    //e
    myDraw(hdc, 433, 276 + 392, 474, 330 + 392, 40, 360, 320);
    LineTo(hdc, 433, 302 + 392);
}
