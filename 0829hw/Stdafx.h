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

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>//�޸� ���� �Լ�
#include <stdio.h>
#include <tchar.h>//���ڼ��� �߰������� �ٲ��ִ� ��ũ�ΰ� ���Ե� �������
// MBCS(��Ƽ����Ʈ ĳ���ͼ�) / WBCS(���̵����Ʈ ĳ���ͼ�)

#include <iostream>
#include <chrono>//�ð� ���� STL���� ���е��� ����(���� �и�) ���� OS �� ���������� �����Ѵ�.
#include <random>
#include <vector>//erase�� �޸� ��ü�� �Ҵ�����, clear�� �޸𸮴� �״�� �ΰ� �����͸� ����
#include <map>//���� RedBlackTree ���� �ڡڡڡڡ�
#include <unordered_map>//�ؽ� �ڷᱸ�� -> �Ϲ��� ��Ȳ������ map���� ������ �ߺ� �����͸� ������� �ʴ´�. ��, ���� �����Ͱ� ���ٸ� �ؽ� �浹 �߻� ���ΰ� �׻� ����.

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

#include "CommonMacroFunction.h"