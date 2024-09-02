//도전과제1.도형 회전
//- 사각형을 회전 시킨다.
//- 외부 라이버러리 X / 외부 문법 x / 순수 WinAPI로만 구현할것
//- hdc를 반드시 사용해야 하고 Rectangle()을 꼭 사용해야 한다.
//- 회전축이 바뀐 상태면 상대 좌표로 이동하게 구현을 해오면 깔끔

#include "Stdafx.h"

//전역변수
HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0,0 };

//함수
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

RECT rc;
RECT _rc1, _rc2;

int centerX;
int centerY;

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
        rc = RectMakeCenter(400, 400, 100, 100);
        _rc1 = RectMakeCenter(WINSIZE_X / 2 + 200, WINSIZE_Y / 2, 100, 100);
        _rc1 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);

        centerX = WINSIZE_X / 2;
        centerY = WINSIZE_Y / 2;

        break;

    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);

        wsprintf(strPT, "X: %d       Y: %d", pt.x, pt.y);//숫자를 문자열로 출력할때(변환)
        TextOut(hdc, 10, 10, strPT, strlen(strPT));

        Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
        DrawRectMake(hdc, rc);

        Rectangle(hdc, _rc1.left, _rc1.top, _rc1.right, _rc1.bottom);
        Rectangle(hdc, _rc2.left, _rc2.top, _rc2.right, _rc2.bottom);

        EllipseMakeCenter(hdc, WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);

        Rectangle(hdc, centerX, centerY, 100, 100);

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_MOUSEMOVE:
        pt.x = LOWORD(lParam);
        pt.y = HIWORD(lParam);

        /*#include<windowsx.h>
        pt.x = GET_X_LPARAM(lParam);
        pt.y = GET_Y_LPARAM(lParam);*/

        InvalidateRect(hWnd, NULL, true);
        break;

    case WM_LBUTTONDOWN:

        centerX = RND->getInt(WINSIZE_X);
        centerY = RND->getInt(WINSIZE_Y);
        InvalidateRect(hWnd, NULL, true);
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

void setWindowSize(int x, int y, int width, int height)
{
    RECT rc = { 0,0,width,height };

    //실제 윈도우 크기 조정
    //AdjustWindowRect(): RECT구조체, 윈도우 스타일, 메뉴 여부
    AdjustWindowRect(&rc, WINSTYLE, false);

    //REXT의 정보로 윈도우 사이즈 세팅
    SetWindowPos(_hWnd, NULL,       //핸들, 부모 윈도우
        x, y,                       //좌표
        (rc.right - rc.left),       //cx
        (rc.bottom - rc.top),       //cy
        SWP_NOZORDER | SWP_NOMOVE); //2D에서 클리핑, 3D에서는 컬링 'ZORDER는 렌더링 우선순위' NO이므로 가려지면 그냥 출력 안하겠다는 의미. NOMOVE는 해상도에 따라 위치변경을 적용하지 않겠다.
}
