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

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>//메모리 복사 함수
#include <stdio.h>
#include <tchar.h>//문자셋을 중간형으로 바꿔주는 매크로가 포함된 헤더파일
// MBCS(멀티바이트 캐릭터셋) / WBCS(와이드바이트 캐릭터셋)

#include <iostream>
#include <chrono>//시간 관련 STL으로 정밀도가 높다(나노 밀리) 또한 OS 와 독립적으로 동작한다.
#include <random>
#include <vector>//erase는 메모리 자체를 할당해제, clear는 메모리는 그대로 두고 데이터만 제거
#include <map>//비선형 RedBlackTree 구조 ★★★★★
#include <unordered_map>//해시 자료구조 -> 일반적 상황에서는 map보다 빠르고 중복 데이터를 허용하지 않는다. 단, 유사 데이터가 많다면 해시 충돌 발생 여부가 항상 존재.

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

#include "CommonMacroFunction.h"