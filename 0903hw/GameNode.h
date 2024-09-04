#pragma once
#include "GImage.h"//������ �����°� ����(�̹��� �Ŵ��� ��)

class GameNode abstract
{
private:
	GImage* _backBuffer;
	void setBackBuffer();

public:
	//HRESULT : �Լ��� �������� ���� ���θ� Ȯ���ϴ� ��ȯ��(32��Ʈ signed ���� (0 �Ǵ� ��� -> ����, ���� -> ����))
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(HDC hdc);

	GImage* getBackBuffer(void) { return _backBuffer; }

	// ���� ���ν���
	// LRESULT : �ݹ� ��ȯ��
	// �� �޼��� ó���� ��ģ�� OS���� ��ȣ�� �ֱ� ���� ��.
	// �� ����ġ������ �� �޼����� ���� ó������ -1,0,1�� �ü���� � �۾��� �ؾ��ϴ��� �˷��ְ� 0�� �߸� ��� �޼��� Done
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	GameNode() {};
	virtual ~GameNode() {}
};