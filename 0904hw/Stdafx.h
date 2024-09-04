#pragma once
// 4005: 그래픽 인터페이스에서 매크로 관련한 경고를 무시하겠다.
#pragma warning(disable : 4005)

// 코드 및 상수 제어 -> OS 레벨에서 관리
// OS에 맞게 converting해줌 또한 converting이 일어나지 않으면 메모리를 먹지 않음.
#include <SDKDDKVer.h>

// 거의 사용되지 않는 내용을 Windows 헤더에서 제외
// 단, 게임에서 회전을 위해 사용되는 ole.h나 ole2.h는 오일러 앵글을 포함하는 것으로 따로 꺼내와야함
#define WIN32_LEAN_AND_MEAN

// ! Windows 헤더 파일
#include <Windows.h>

// 라이브러리
// #pragma comment (lib, "msimg32.lib")

// C 런타임 헤더파일
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>//메모리 함수(memcpy,memset 등)
#include <stdio.h>
#include <tchar.h>//문자셋을 중간형으로 바꿔주는 매크로가 포함된 헤더파일
// MBCS(멀티바이트 캐릭터셋) / WBCS(와이드바이트 캐릭터셋)
#include <assert.h>

// C++ 런타임 헤더파일
#include <iostream>
#include <chrono>//시간 관련 STL으로 정밀도가 높다(나노 밀리) 또한 OS 와 독립적으로 동작한다.
#include <random>
#include <vector>//erase는 메모리 자체를 할당해제, clear는 메모리는 그대로 두고 데이터만 제거
#include <map>//비선형 RedBlackTree 구조 ★★★★★
#include <unordered_map>//해시 자료구조 -> 일반적 상황에서는 map보다 빠르고 중복 데이터를 허용하지 않는다. 단, 유사 데이터가 많다면 해시 충돌 발생 여부가 항상 존재.
#include <list>
#include <bitset>//비트 연산을 좀 더 사람 친화적 / 함수화 시켜놓은 STL
#include <cassert>

using std::vector;
using std::list;
using std::string;
using std::wstring;
using std::bitset;

/*
// 라이브러리
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

// 팩토리
ID2D1Factory* _ID2DFactory = nullptr;
ID2D1HwndRenderTarget* _ID2DRenderTarget = nullptr;
*/

// Stdafx (Standard Application Frameworks)
//	- VS를 이용하여 프로젝트를 생성하면 생성되는 클래스 약어 -> MS에서 정의
//	- 표준 어플리케이션 프레임워크 툴

// 내가 만든 헤더 파일
#include "CommonMacroFunction.h"
#include "RandomFunction.h"
#include "KeyManager.h"

// 디자인 패턴
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()

// 매크로
#define WINNAME		(LPSTR)(TEXT("WindowsAPI"))
#define WINSTART_X	700
#define WINSTART_Y	0
#define WINSIZE_X	1000
#define WINSIZE_Y	1000
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

// 매크로 함수
#define SAFE_DELETE(p)			{if(p) {delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}

// 전역 변수
extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;