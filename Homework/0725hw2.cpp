#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

enum class Pattern
{
	SPADE,CLOVER,HEART,DIAMOND,EMPTY
};

struct Card
{
	Pattern pattern = Pattern::EMPTY;
	int number = 0;

	void printCard()
	{
		switch (pattern)
		{
		case Pattern::SPADE:
			cout << "♠";
			break;
		case Pattern::CLOVER:
			cout << "♣";
			break;
		case Pattern::HEART:
			cout << "♥";
			break;
		case Pattern::DIAMOND:
			cout << "◆";
			break;
		default:
			cout << "EMPTY";
			break;
		}

		switch (number)
		{
		case 1:
			cout << 'A';
			break;

		case 11:
			cout << 'J';
			break;

		case 12:
			cout << 'Q';
			break;

		case 13 :
			cout << 'K';
			break;

		default:
			cout << number;
			break;
		}
	}
};

void main()
{
	int money = 10000;

	Card deck[52];

	//덱 초기화
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deck[i * 13 + j].pattern = static_cast<Pattern>(i);
			deck[i * 13 + j].number = j + 1;
		}
	}

	int cardIndex = 0;

	//덱 섞기
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 51);

	for (int i = 0; i < 1000; i++)
	{
		Card temp;
		int dest, sour;
		dest = dist(gen);
		sour = dist(gen);

		//swap
		temp = deck[dest];
		deck[dest] = deck[sour];
		deck[sour] = temp;
	}

	//게임 시작
	int comNum1, comNum2, userNum;

	for (int i = 0; i < 17; i++)
	{
		//컴퓨터의 패 출력
		cout << "컴퓨터의 패 : ";
		comNum1 = deck[cardIndex].number;
		deck[cardIndex++].printCard();
		cout << ' ';
		comNum2 = deck[cardIndex].number;
		deck[cardIndex++].printCard();
		cout << endl << endl;

		//베팅 금액 설정
		int bet;
		do
		{
			cout << "현재 소지금 : " << money << endl;
			cout << "베팅하실 금액을 입력하세요(최소 1000, 현재 소지금을 넘을 순 없음.) : ";
			cin >> bet;
		} while (bet < 1000 || bet > money);

		//유저의 패 출력
		cout << "유저의 패 : ";
		userNum = deck[cardIndex].number;
		deck[cardIndex++].printCard();
		cout << endl;

		//결과 출력
		if ((comNum1 < userNum && comNum2 > userNum) || (comNum1 > userNum && comNum2 < userNum))
		{
			cout << "승리" << endl;
			money += bet * 2;
			cout << bet * 2 << "원 획득, 현재 보유금 : " << money << "원" << endl;
		}
		else if (comNum1 == userNum || comNum2 == userNum)
		{
			cout << "비김" << endl;
			money -= bet;
			cout << bet << "원을 잃었습니다. 현재 보유금 : " << money << "원" << endl;
		}
		else
		{
			cout << "패배" << endl;
			money -= bet * 2;
			cout << bet * 2 << "원을 잃었습니다. 현재 보유금 : " << money << "원" << endl;
		}

		//게임 종료
		if (money < 1000)
		{
			cout << "현재 보유금이 최소 베팅금액보다 적으므로 게임을 종료합니다." << endl;
			break;
		}

		cout << endl;
	}
}