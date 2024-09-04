#pragma once
// 4005: �׷��� �������̽����� ��ũ�� ������ ��� �����ϰڴ�.
#pragma warning(disable : 4005)

// �ڵ� �� ��� ���� -> OS �������� ����
// OS�� �°� converting���� ���� converting�� �Ͼ�� ������ �޸𸮸� ���� ����.
#include <SDKDDKVer.h>

// ���� ������ �ʴ� ������ Windows ������� ����
// ��, ���ӿ��� ȸ���� ���� ���Ǵ� ole.h�� ole2.h�� ���Ϸ� �ޱ��� �����ϴ� ������ ���� �����;���
#define WIN32_LEAN_AND_MEAN

// ! Windows ��� ����
#include <Windows.h>

// ���̺귯��
// #pragma comment (lib, "msimg32.lib")

// C ��Ÿ�� �������
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>//�޸� �Լ�(memcpy,memset ��)
#include <stdio.h>
#include <tchar.h>//���ڼ��� �߰������� �ٲ��ִ� ��ũ�ΰ� ���Ե� �������
// MBCS(��Ƽ����Ʈ ĳ���ͼ�) / WBCS(���̵����Ʈ ĳ���ͼ�)
#include <assert.h>

// C++ ��Ÿ�� �������
#include <iostream>
#include <chrono>//�ð� ���� STL���� ���е��� ����(���� �и�) ���� OS �� ���������� �����Ѵ�.
#include <random>
#include <vector>//erase�� �޸� ��ü�� �Ҵ�����, clear�� �޸𸮴� �״�� �ΰ� �����͸� ����
#include <map>//���� RedBlackTree ���� �ڡڡڡڡ�
#include <unordered_map>//�ؽ� �ڷᱸ�� -> �Ϲ��� ��Ȳ������ map���� ������ �ߺ� �����͸� ������� �ʴ´�. ��, ���� �����Ͱ� ���ٸ� �ؽ� �浹 �߻� ���ΰ� �׻� ����.
#include <list>
#include <bitset>//��Ʈ ������ �� �� ��� ģȭ�� / �Լ�ȭ ���ѳ��� STL
#include <cassert>

using std::vector;
using std::list;
using std::string;
using std::wstring;
using std::bitset;

/*
// ���̺귯��
#include <D2D1.h>
#include <d2d1helper.h>
#include <d3dx9.h>
#include <D3Dx11.h>
#include <d3d11shader.h>
#include <dinput.h>

#pragma comment (lib, "d2d1.lib")
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")

// ���丮
ID2D1Factory* _ID2DFactory = nullptr;
ID2D1HwndRenderTarget* _ID2DRenderTarget = nullptr;
*/

// Stdafx (Standard Application Frameworks)
//	- VS�� �̿��Ͽ� ������Ʈ�� �����ϸ� �����Ǵ� Ŭ���� ��� -> MS���� ����
//	- ǥ�� ���ø����̼� �����ӿ�ũ ��

// ���� ���� ��� ����
#include "CommonMacroFunction.h"
#include "RandomFunction.h"
#include "KeyManager.h"

// ������ ����
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()

// ��ũ��
#define WINNAME		(LPSTR)(TEXT("WindowsAPI"))
#define WINSTART_X	700
#define WINSTART_Y	0
#define WINSIZE_X	1000
#define WINSIZE_Y	1000
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

// ��ũ�� �Լ�
#define SAFE_DELETE(p)			{if(p) {delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}

// ���� ����
extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;