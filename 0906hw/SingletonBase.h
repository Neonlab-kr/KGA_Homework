#pragma once
// SingletonBase

/*
- 단 하나의 객체만 생성되어 있음을 보장함.
- 애플리케이션이 시작될 때 어떤 클래스가 최초 한번만 메모리를 할당하고(Static) 그 메모리에 인스턴스를 만들어 사용하는 디자인패턴.
- 생성자가 여러 차례 호출되더라도 실제로 생성되는 객체는 하나고 최초 생성 이후에 호출된 생성자는 최초에 생성한 객체를 반환.
- 싱글톤 패턴은 단 하나의 인스턴스를 생성해 사용하는 디자인 패턴
- 인스턴스가 필요 할 때 똑같은 인스턴스를 만들어 내는 것이 아니라, 동일(기존) 인스턴스를 사용하게함
- 단점은 결합도가 높아질 수 있다.
*/

/*
싱글톤 : 프로젝트 전체에서 1개만 존재해야 하는 객체 / 클래스 -> 또는 공유하는 클래스
장점 : 인스턴스를 생성하지 않으면 메모리를 사용하지 않음
단점 : 결합도
*/

//인라인과 템플릿 그리고 접근자/설정자는 헤더파일 구현을 원칙으로 한다.
#include "Stdafx.h"

template <class T>
class SingletonBase
{
protected:
	static T* singleton;

	SingletonBase() {}
	~SingletonBase() {}

public:
	static T* getSingleton(void);
	void releaseSingleton(void);
};

template <typename T>
T* SingletonBase<T>::singleton = 0;

//가져오는 함수
template<typename T>
T* SingletonBase<T>::getSingleton(void)
{
	if (!singleton) singleton = new T;
	return singleton;
}

//해제하는 함수
template<typename T>
inline void SingletonBase<T>::releaseSingleton(void)
{
	if (singleton)
	{
		delete singleton;
		singleton = 0;
	}
}
