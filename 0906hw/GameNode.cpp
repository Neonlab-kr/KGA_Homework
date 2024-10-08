#include "Stdafx.h"
#include "GameNode.h"


HRESULT GameNode::init(void)
{
    SetTimer(_hWnd, 1, 10, NULL);

    KEYMANAGER->init();
    RND->init();
    SCENEMANAGER->init();

    setBackBuffer();

    return S_OK;//함수의 성공
}

void GameNode::setBackBuffer()//백 버퍼를 통해 메모리를 사용하고 CPU를 살림
{
    _backBuffer = new GImage();
    _backBuffer->init(WINSIZE_X, WINSIZE_Y);
}


void GameNode::release(void)
{
    KillTimer(_hWnd, 1);

    KEYMANAGER->releaseSingleton();
    RND->releaseSingleton();
    SCENEMANAGER->releaseSingleton();

    SAFE_DELETE(_backBuffer);
}

// 갱신 -> 타이머의 주기(정밀도)
void GameNode::update(void)
{
    InvalidateRect(_hWnd, NULL, false);
}

//재정의를 전제로 하는 녀석이라 정의하지 않음.
void GameNode::render(HDC)
{
}

LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (iMessage)
    {
    case WM_TIMER:
        this->update();
        break;

    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);
        this->render(hdc);
        EndPaint(hWnd, &ps);
    }
    break;

    case WM_MOUSEMOVE:
        _ptMouse.x = LOWORD(lParam);
        _ptMouse.y = HIWORD(lParam);
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

    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
