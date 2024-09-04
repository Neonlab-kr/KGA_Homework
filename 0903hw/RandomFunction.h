#pragma once
//RandomFunction
#include "SingletonBase.h"

class RandomFunction : public SingletonBase <RandomFunction>
{
public :
	RandomFunction()
	{
		// API ���� �Լ�
		//GetTickCount(): API �Լ��� OS�� ���õ� ���� ��� �ð��� üũ
		//������ �и� ���� -> �и� ���� �����̱� ������ �Ը� ũ�� ���� ������ ����.
		srand(GetTickCount());
	}
	~RandomFunction() {}

	HRESULT init(void) { return S_OK; }
	
	inline int getInt(int num)
	{
		return rand() % num;
	}

	//fromNum <= toNum�� �������� ������ ������ ���� inline�� Ǯ��
	inline int getFromTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}

	//float���ʹ� �ε��Ҽ��� ������ �����Ƿ� inline���� ����X
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