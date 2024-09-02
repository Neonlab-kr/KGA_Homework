//과제1.사각형 4단 밀기
//- 사각형의 갯수는 총 4개
//- 마우스로 화면에 그려진 4개의 사각형중 아무거나 선택해 자유롭게 움직일 수 있어야 한다.
//- 좌클릭으로 누른채로 이동.
//- 크기 조절은 마우스의 한쪽을 찍고 움직이면 늘어나는 형태
//- 움직임도 가능하고 크기 또한 조절이 가능해야 함.
//- 마우스 왼 / 오
//- 마우스로 움직이고 있는 사각형이 다른 사각형과 충돌되면 충돌된 사각형은 자연스럽게 밀려난다.(타이머 사용)
//
//※ 충돌 함수 사용 금지

#include "Stdafx.h"

//전역변수
HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0,0 };

struct myRC
{
    RECT rc = {0,0,0,0};
    bool moveActivate = false;
    bool changeActivate = false;
    bool changeX = false;
    bool changeY = false;
    int dx = 0;
    int dy = 0;
    int startTimeX = 0;
    int startTimeY = 0;
    POINT startPoint = { 0,0 };
};

myRC RCArray[4];
int rcSelIndex = 0;

//함수
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

bool CheckCollision(const myRC& r1, const myRC& r2);
void ResolveCollision(myRC& r1, myRC& r2);

template <typename T>
void swap(T&a, T&b);

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
    static POINT prevPt = { 0,0 };
    char strPT[128];

    switch (iMessage)
    {
    case WM_CREATE:
        RCArray[0].rc = RectMakeCenter(WINSIZE_X / 4, WINSIZE_Y / 4, 100, 100);
        RCArray[0].dx = RCArray[0].dy = 0;
        RCArray[1].rc = RectMakeCenter(WINSIZE_X / 4 * 3, WINSIZE_Y / 4, 100, 100);
        RCArray[1].dx = RCArray[1].dy = 0;
        RCArray[2].rc = RectMakeCenter(WINSIZE_X / 4, WINSIZE_Y / 4 * 3, 100, 100);
        RCArray[2].dx = RCArray[2].dy = 0;
        RCArray[3].rc = RectMakeCenter(WINSIZE_X / 4 * 3, WINSIZE_Y / 4 * 3, 100, 100);
        RCArray[3].dx = RCArray[3].dy = 0;
        SetTimer(hWnd, 1, 5, NULL);
        break;

    case WM_TIMER:
    {
        bool collided[4] = { false, false, false, false };

        for (int i = 0; i < 4; i++)
        {
            if (RCArray[i].moveActivate) continue;

            for (int j = 0; j < 4; j++)
            {
                if (i == j || collided[j]) continue;

                if (CheckCollision(RCArray[i], RCArray[j]))
                {
                    ResolveCollision(RCArray[i], RCArray[j]);
                    collided[i] = collided[j] = true;
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (RCArray[i].moveActivate) continue;
            if ((RCArray[i].rc.left + RCArray[i].dx < 0) || (RCArray[i].rc.right + RCArray[i].dx >= WINSIZE_X))
            {
                RCArray[i].dx = -RCArray[i].dx;
            }

            if ((RCArray[i].rc.top + RCArray[i].dy < 0) || (RCArray[i].rc.bottom + RCArray[i].dy > WINSIZE_Y))
            {
                RCArray[i].dy = -RCArray[i].dy;
            }

            RCArray[i].rc.left += RCArray[i].dx;
            RCArray[i].rc.right += RCArray[i].dx;
            RCArray[i].rc.top += RCArray[i].dy;
            RCArray[i].rc.bottom += RCArray[i].dy;

            int friction = 2;

            if (RCArray[i].dx > friction) RCArray[i].dx -= friction;
            else if (RCArray[i].dx < -friction) RCArray[i].dx += friction;
            else RCArray[i].dx = 0;

            if (RCArray[i].dy > friction) RCArray[i].dy -= friction;
            else if (RCArray[i].dy < -friction) RCArray[i].dy += friction;
            else RCArray[i].dy = 0;
        }

        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;

    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);
        DrawRectMake(hdc, RCArray[0].rc);
        DrawRectMake(hdc, RCArray[1].rc);
        DrawRectMake(hdc, RCArray[2].rc);
        DrawRectMake(hdc, RCArray[3].rc);
        EndPaint(hWnd, &ps);
    }
    break;

    case WM_MOUSEMOVE:
        pt.x = LOWORD(lParam);
        pt.y = HIWORD(lParam);
        switch (wParam)
        {
        case MK_LBUTTON:
            if (RCArray[rcSelIndex].moveActivate)
            {
                hdc = GetDC(hWnd);
                RCArray[rcSelIndex].rc.left += pt.x - prevPt.x;
                RCArray[rcSelIndex].rc.right += pt.x - prevPt.x;
                RCArray[rcSelIndex].rc.top += pt.y - prevPt.y;
                RCArray[rcSelIndex].rc.bottom += pt.y - prevPt.y;

                if ((pt.x - prevPt.x > 0) != RCArray[rcSelIndex].changeX) RCArray[rcSelIndex].startTimeX = GetTickCount() / 100;
                if ((pt.y - prevPt.y > 0) != RCArray[rcSelIndex].changeY) RCArray[rcSelIndex].startTimeY = GetTickCount() / 100;

                if (pt.x - prevPt.x > 0) RCArray[rcSelIndex].changeX = true;
                else RCArray[rcSelIndex].changeX = false;

                if (pt.y - prevPt.y > 0) RCArray[rcSelIndex].changeY = true;
                else RCArray[rcSelIndex].changeY = false;

                ReleaseDC(hWnd, hdc);
                InvalidateRect(hWnd, NULL, true);
            }
            break;
        case MK_RBUTTON:
            if (RCArray[rcSelIndex].changeActivate)
            {
                hdc = GetDC(hWnd);
                if (RCArray[rcSelIndex].changeX)
                {
                    RCArray[rcSelIndex].rc.right += pt.x - prevPt.x;
                }
                else
                {
                    RCArray[rcSelIndex].rc.left += pt.x - prevPt.x;
                }
                if (RCArray[rcSelIndex].changeY)
                {
                    RCArray[rcSelIndex].rc.bottom += pt.y - prevPt.y;
                }
                else
                {
                    RCArray[rcSelIndex].rc.top += pt.y - prevPt.y;
                }
                ReleaseDC(hWnd, hdc);
                InvalidateRect(hWnd, NULL, true);
            }
            break;
        }
        prevPt = pt;
        break;

    case WM_LBUTTONDOWN:
        for (int i = 0; i < 4; i++)
        {
            if ((pt.x < RCArray[i].rc.right) && (pt.x > RCArray[i].rc.left) && (pt.y < RCArray[i].rc.bottom) && (pt.y > RCArray[i].rc.top))
            {
                RCArray[i].moveActivate = true;
                rcSelIndex = i;
                RCArray[rcSelIndex].startTimeX = GetTickCount()/100;
                RCArray[rcSelIndex].startTimeY = GetTickCount()/100;
                RCArray[rcSelIndex].startPoint = PointMake(pt.x, pt.y);
                break;
            }
        }
        break;

    case WM_LBUTTONUP:
    {
        RCArray[rcSelIndex].moveActivate = false;

        RCArray[rcSelIndex].dx = ((pt.x - RCArray[rcSelIndex].startPoint.x)/2) / (int)(GetTickCount() / 100 - RCArray[rcSelIndex].startTimeX + 1);
        RCArray[rcSelIndex].dy = ((pt.y - RCArray[rcSelIndex].startPoint.y)/2) / (int)(GetTickCount() / 100 - RCArray[rcSelIndex].startTimeY + 1);
    }
    break;

    case WM_RBUTTONDOWN:
        for (int i = 0; i < 4; i++)
        {
            RCArray[i].changeActivate = (pt.x < RCArray[i].rc.right) && (pt.x > RCArray[i].rc.left) && (pt.y < RCArray[i].rc.bottom) && (pt.y > RCArray[i].rc.top);
            if (RCArray[i].changeActivate)
            {
                RCArray[i].changeX = pt.x > (RCArray[i].rc.right + RCArray[i].rc.left) / 2;

                RCArray[i].changeY = pt.y > (RCArray[i].rc.bottom + RCArray[i].rc.top) / 2;
                rcSelIndex = i;
            }
        }
        break;

    case WM_RBUTTONUP:
        if (RCArray[rcSelIndex].rc.left > RCArray[rcSelIndex].rc.right)
        {
            swap(RCArray[rcSelIndex].rc.left, RCArray[rcSelIndex].rc.right);
        }
        if (RCArray[rcSelIndex].rc.top > RCArray[rcSelIndex].rc.bottom)
        {
            swap(RCArray[rcSelIndex].rc.top, RCArray[rcSelIndex].rc.bottom);
        }
        RCArray[rcSelIndex].changeActivate = false;
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case 'R':
            RCArray[0].rc = RectMakeCenter(WINSIZE_X / 4, WINSIZE_Y / 4, 100, 100);
            RCArray[0].dx = RCArray[0].dy = 0;
            RCArray[1].rc = RectMakeCenter(WINSIZE_X / 4 * 3, WINSIZE_Y / 4, 100, 100);
            RCArray[1].dx = RCArray[1].dy = 0;
            RCArray[2].rc = RectMakeCenter(WINSIZE_X / 4, WINSIZE_Y / 4 * 3, 100, 100);
            RCArray[2].dx = RCArray[2].dy = 0;
            RCArray[3].rc = RectMakeCenter(WINSIZE_X / 4 * 3, WINSIZE_Y / 4 * 3, 100, 100);
            RCArray[3].dx = RCArray[3].dy = 0;
            InvalidateRect(hWnd, NULL, true);
            break;
        case VK_ESCAPE:
            PostMessage(hWnd, WM_DESTROY, 0, 0);
            break;
        }
        break;

    case WM_DESTROY:
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        return 0;
    }

    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void setWindowSize(int x, int y, int width, int height)
{
    RECT rc = { 0,0,width,height };
    AdjustWindowRect(&rc, WINSTYLE, false);
    SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);;
}

template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

bool CheckCollision(const myRC& r1, const myRC& r2)
{
    return (r1.rc.left < r2.rc.right && r1.rc.right > r2.rc.left && r1.rc.top < r2.rc.bottom && r1.rc.bottom > r2.rc.top);
}

void ResolveCollision(myRC& r1, myRC& r2)
{ 
    int overlapX, overlapY;
    overlapX = (((r1.rc.right - r2.rc.left) < (r2.rc.right - r1.rc.left)) ? (r1.rc.right - r2.rc.left) : (r2.rc.right - r1.rc.left));
    overlapY = (((r1.rc.bottom - r2.rc.top) < (r2.rc.bottom - r1.rc.top)) ? (r1.rc.bottom - r2.rc.top) : (r2.rc.bottom - r1.rc.top));

    if(!r1.moveActivate)
    {
        if (overlapX < overlapY)
        {
            r1.dx += (r1.rc.top < r2.rc.top) ? -overlapY / 2 : overlapY / 2;
            r1.dx /= 2;
        }
        else
        {
            r1.dy += (r1.rc.left < r2.rc.left) ? -overlapX / 2 : overlapX / 2;
            r1.dy /= 2;
        }
    }

    if (!r2.moveActivate)
    {
        if (overlapX < overlapY)
        {
            r2.dx += (r2.rc.top < r1.rc.top) ? -overlapY / 2 : overlapY / 2;
            r2.dx /= 2;
        }
        else
        {
            r2.dy += (r2.rc.left < r1.rc.left) ? -overlapX / 2 : overlapX / 2;
            r2.dy /= 2;
        }
    }
}