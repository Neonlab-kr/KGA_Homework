#pragma once
//RandomFunction
#include "SingletonBase.h"

class RandomFunction : public SingletonBase <RandomFunction>
{
public:
	RandomFunction()
	{
		// API 공용 함수
		//GetTickCount(): API 함수로 OS가 부팅된 후의 경과 시간을 체크
		//단위는 밀리 세턴 -> 밀리 세컨 단위이기 때문에 규모가 크지 않은 난수에 좋다.
		srand(GetTickCount());
	}
	~RandomFunction() {}

	HRESULT init(void) { return S_OK; }

	inline int getInt(int num)
	{
		return rand() % num;
	}

	//fromNum <= toNum을 보장하지 않지만 조건이 들어가면 inline이 풀림
	inline int getFromTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}

	//float부터는 부동소수점 연산이 있으므로 inline으로 선언X
	float getFloat(void)
	{
		return (float)rand() / (float)RAND_MAX;
	}

	float getFloat(float num)
	{
		return (float)rand() / (float)RAND_MAX * num;
	}

	float getFromFloatTo(float fromNum, float toNum)
	{
		float rnd = (float)rand() / (float)RAND_MAX;
		return (rnd * (toNum - fromNum + 1) + fromNum);
	}
};