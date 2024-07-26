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
			cout << "��";
			break;
		case Pattern::CLOVER:
			cout << "��";
			break;
		case Pattern::HEART:
			cout << "��";
			break;
		case Pattern::DIAMOND:
			cout << "��";
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

	//�� �ʱ�ȭ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deck[i * 13 + j].pattern = static_cast<Pattern>(i);
			deck[i * 13 + j].number = j + 1;
		}
	}

	int cardIndex = 0;

	//�� ����
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

	//���� ����
	int comNum1, comNum2, userNum;

	for (int i = 0; i < 17; i++)
	{
		//��ǻ���� �� ���
		cout << "��ǻ���� �� : ";
		comNum1 = deck[cardIndex].number;
		deck[cardIndex++].printCard();
		cout << ' ';
		comNum2 = deck[cardIndex].number;
		deck[cardIndex++].printCard();
		cout << endl << endl;

		//���� �ݾ� ����
		int bet;
		do
		{
			cout << "���� ������ : " << money << endl;
			cout << "�����Ͻ� �ݾ��� �Է��ϼ���(�ּ� 1000, ���� �������� ���� �� ����.) : ";
			cin >> bet;
		} while (bet < 1000 || bet > money);

		//������ �� ���
		cout << "������ �� : ";
		userNum = deck[cardIndex].number;
		deck[cardIndex++].printCard();
		cout << endl;

		//��� ���
		if ((comNum1 < userNum && comNum2 > userNum) || (comNum1 > userNum && comNum2 < userNum))
		{
			cout << "�¸�" << endl;
			money += bet * 2;
			cout << bet * 2 << "�� ȹ��, ���� ������ : " << money << "��" << endl;
		}
		else if (comNum1 == userNum || comNum2 == userNum)
		{
			cout << "���" << endl;
			money -= bet;
			cout << bet << "���� �Ҿ����ϴ�. ���� ������ : " << money << "��" << endl;
		}
		else
		{
			cout << "�й�" << endl;
			money -= bet * 2;
			cout << bet * 2 << "���� �Ҿ����ϴ�. ���� ������ : " << money << "��" << endl;
		}

		//���� ����
		if (money < 1000)
		{
			cout << "���� �������� �ּ� ���ñݾ׺��� �����Ƿ� ������ �����մϴ�." << endl;
			break;
		}

		cout << endl;
	}
}