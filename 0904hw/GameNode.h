#pragma once
#include "GImage.h"//패턴이 들어오는게 좋음(이미지 매니저 등)

class GameNode abstract
{
private:
	GImage* _backBuffer;
	void setBackBuffer();

public:
	//HRESULT : 함수의 성공적인 종료 여부를 확인하는 반환형(32비트 signed 정수 (0 또는 양수 -> 성공, 음수 -> 실패))
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);

	GImage* getBackBuffer(void) { return _backBuffer; }

	// 메인 프로시저
	// LRESULT : 콜백 반환형
	// ㄴ 메세지 처리를 마친후 OS에게 신호를 주기 위한 값.
	// ㄴ 스위치문에서 각 메세지에 대한 처리값을 -1,0,1로 운영체제에 어떤 작업을 해야하는지 알려주고 0이 뜨면 모든 메세지 Done
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	GameNode() {};
	virtual ~GameNode() {}
};