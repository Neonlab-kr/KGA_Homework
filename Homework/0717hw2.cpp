#include <iostream>
#include <string>
#include <time.h>

using std::cout;
using std::endl;
using std::string;

unsigned short RandomNumber(unsigned short min, unsigned short max);
void PrintWeaponInfo(string name, string type, string traits, unsigned short price, unsigned short damage);
void PrintArmouryInfo(string name, string type, string traits, unsigned short price, unsigned short armour);

void main()
{
	string name, type, traits;
	unsigned short price, damage, armour;

	//TODO -  무기 그래픽 작성
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　■■■■　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　■■　■■■■■■■■■　　　　　" << endl;
	cout << "　　　　　　　　　　　　■■■■■■■■■■■■■■　　　　" << endl;
	cout << "　　　　　　　　　　　■■■■■■■■■■■■■■■■　　　" << endl;
	cout << "　　　　　　　　　　■■■■■■■■■■■■■■■■■■　　" << endl;
	cout << "　　　　　　　　　　■■■■■■■■■■■■■■■■■■■　" << endl;
	cout << "　　　　　　　　　　■■■■■■■■■■■■　　　　　■■■" << endl;
	cout << "　　　　　　　　　　■■■■■■■■　■■■　　　　　　　■" << endl;
	cout << "　　　　　　　　　　■■■■■■■　　　■　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　■　　　　■　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　■　　■■■■■　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　■　■　　■■　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　■　■　　■■　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　■　■　　■■■　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　■　　■■■■■　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　■　　　　■　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　■■■■■■■　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　■■■■■■■　　　　　　　　　" << endl;
	cout << "■　　　　　　　　　　　■■■■■■■■■　　　　　　　　　" << endl;
	cout << "■■　　　　　　■■■■■■■■■■■■■　　　　　　　　　" << endl;
	cout << "　■■■■■■■■■■■■■■■■■■■■　　　　　　　　　" << endl;
	cout << "　　■■■■■■■■■■■■■■■■■■　　　　　　　　　　" << endl;
	cout << "　　　■■■■■■■■■■■■■■■　　　　　　　　　　　　" << endl;
	cout << "　　　　■■■■■■■■■■■■■　　　　　　　　　　　　　" << endl;
	cout << "　　　　　■■■■■■■■■■　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　■■■■■■　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	name = "반월검";
	type = "검";
	traits = "확률적으로 적에게 출혈 상태이상을 발생시킵니다.";
	price = 7800;
	damage = RandomNumber(10,15);
	PrintWeaponInfo(name, type, traits, price, damage);

	name = "요르시카의 성령";
	type = "성령";
	traits = "기술 사용시 일정 시간 동안 HP를 극히 서서히 회복 한다";
	price = 25000;
	damage = RandomNumber(0, 5);
	PrintWeaponInfo(name, type, traits, price, damage);

	name = "로스릭 기사의 대검";
	type = "특대검";
	traits = "적에게 공격력의 40%에 해당하는 벼락 속성데미지를 추가로 부여한다.";
	price = 12800;
	damage = RandomNumber(40, 70);
	PrintWeaponInfo(name, type, traits, price, damage);

	//TODO -  방어구 그래픽 작성
	cout << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　■■■■　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　■■■■■■■■■　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　■　　　　■　■■■■　　　　　　　　　　" << endl;
	cout << "　　　　　　　　■　　　　■　　■■■■■　　　　　　　　　" << endl;
	cout << "　　　　　　　■　　　　　■　　　■■■■　　　　　　　　　" << endl;
	cout << "　　　　　　■　■　　　　■　　　　■■■■　　　　　　　　" << endl;
	cout << "　　　　　　■■■■　　■■■　　　■■■■■　　　　　　　" << endl;
	cout << "　　　　　■■■■■■■■■■■■■　■■■■■　　　　　　" << endl;
	cout << "　　　　■■■■■　■■■■■■■■　　■■■■■　　　　　" << endl;
	cout << "　　　　■■■■　　■■■■■■■■　　　■■■■■　　　　" << endl;
	cout << "　　　　　■■　　　■■■■■■■■■　　　■■■■　　　　" << endl;
	cout << "　　　　　　　　　　■■■■■■■■■　　　　■■　　　　　" << endl;
	cout << "　　　　　　　　　　■　　　　　　　■　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　■　　■■■■　　■■　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　■　　■■■■　　■■　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　■　　　■■■■　　■　　　　　　　　　　" << endl;
	cout << "　　　　　　　　■■　　　■■■■　　■　　　　　　　　　　" << endl;
	cout << "　　　　　　　　■■■■■■■■■■■■　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　■■■■■■■■　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;
	name = "패치의 갑옷";
	type = "가죽 갑옷";
	traits = "소리를 죽이고, 어둠에 숨기 위한 것. 은신 범위를 1칸 늘려준다.";
	price = 8000;
	armour = RandomNumber(5, 10);
	PrintArmouryInfo(name, type, traits, price, armour);

	name = "허수아비의 넝마";
	type = "천 갑옷";
	traits = "피격시 착용자에게 매우 낮은 확률로 중독 상태이상을 발생시킨다.";
	price = 4500;
	armour = RandomNumber(0, 7);
	PrintArmouryInfo(name, type, traits, price, armour);

}

unsigned short RandomNumber(unsigned short min, unsigned short max)
{
	//랜덤한 값을 담을 변수 선언
	unsigned short randomNumber;

	//랜덤 시드
	srand(time(NULL));

	//랜덤으로 생성된 숫자 할당
	randomNumber = rand() % (max - min + 1) + min;

	return randomNumber;
}

void PrintWeaponInfo(string name, string type, string traits, unsigned short price, unsigned short damage)
{
	cout << endl;
	cout << " = ============================================================================ = " << endl;
	cout << "이름 : " << name << endl;
	cout << "종류 : " << type << endl;
	cout << "데미지 : " << damage << endl;
	cout << "가격 : " << price << endl;
	cout << "특성 : " << traits << endl;
	cout << " = ============================================================================ = " << endl;
}

void PrintArmouryInfo(string name, string type, string traits, unsigned short price, unsigned short armour)
{
	cout << endl;
	cout << " = ============================================================================ = " << endl;
	cout << "이름 : " << name << endl;
	cout << "종류 : " << type << endl;
	cout << "방어력 : " << armour << endl;
	cout << "가격 : " << price << endl;
	cout << "특성 : " << traits << endl;
	cout << " = ============================================================================ = " << endl;
}