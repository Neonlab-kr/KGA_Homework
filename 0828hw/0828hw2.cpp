#include <Windows.h>
#include <tchar.h>

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("Windows API");

void gugudan(HDC, int);

RECT gugudanArea[8] =
{
    { 0,0,262,262 },
    { 262,0,524,262 },
    { 524,0,786,262 },
    { 0,262,262,524 },
    { 262,262,524,524 },
    { 524,262,786,524 },
    { 0,524,262,786 },
    { 262,524,524,786 }
};

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

    switch (iMessage)
    {
    case WM_CREATE:
        break;

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        EndPaint(hWnd, &ps);
        break;

    case WM_LBUTTONDOWN:
        if ((count >= 0) && (count <= 7))
        {
            hdc = GetDC(hWnd);
            gugudan(hdc, count + 2);
            ReleaseDC(hWnd, hdc);
            count++;
        }
        break;

    case WM_RBUTTONDOWN:
        if ((count >= 1) && (count <= 8))
        {
            InvalidateRect(hWnd, &gugudanArea[count - 1], true);
            count--;
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

//void gugudan(HDC hdc, int num)
//{
//    for (int i = 2; i <= 9; i++)
//    {
//        std::string str = std::to_string(num) + " * " + std::to_string(i) + " = " + std::to_string(num * i);
//        TextOut(hdc, gugudanArea[num - 2].left, gugudanArea[num - 2].top + ((i - 2) * 32), str.c_str(), strlen(str.c_str()));
//    }
//}

void gugudan(HDC hdc, int num)
{
    char numCh[3];
    char iCh[3];
    char resultCh[4];
    char str[11];

    _itoa_s(num, numCh, 10);

    for (int i = 2; i <= 9; i++)
    {
        strcpy_s(str, sizeof(str), numCh);
        _itoa_s(i, iCh, 10);
        _itoa_s(num * i, resultCh, 10);

        strcat_s(str, sizeof(str), " * ");
        strcat_s(str, sizeof(str), iCh);
        strcat_s(str, sizeof(str), " = ");
        strcat_s(str, sizeof(str), resultCh);

        TextOut(hdc, gugudanArea[num - 2].left, gugudanArea[num - 2].top + ((i - 2) * 32), str, strlen(str));
    }
}