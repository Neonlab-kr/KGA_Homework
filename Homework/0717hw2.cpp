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

	//TODO -  ¹«±â ±×·¡ÇÈ ÀÛ¼º
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡á¡á¡á" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	name = "¹Ý¿ù°Ë";
	type = "°Ë";
	traits = "È®·üÀûÀ¸·Î Àû¿¡°Ô ÃâÇ÷ »óÅÂÀÌ»óÀ» ¹ß»ý½ÃÅµ´Ï´Ù.";
	price = 7800;
	damage = RandomNumber(10,15);
	PrintWeaponInfo(name, type, traits, price, damage);

	name = "¿ä¸£½ÃÄ«ÀÇ ¼º·É";
	type = "¼º·É";
	traits = "±â¼ú »ç¿ë½Ã ÀÏÁ¤ ½Ã°£ µ¿¾È HP¸¦ ±ØÈ÷ ¼­¼­È÷ È¸º¹ ÇÑ´Ù";
	price = 25000;
	damage = RandomNumber(0, 5);
	PrintWeaponInfo(name, type, traits, price, damage);

	name = "·Î½º¸¯ ±â»çÀÇ ´ë°Ë";
	type = "Æ¯´ë°Ë";
	traits = "Àû¿¡°Ô °ø°Ý·ÂÀÇ 40%¿¡ ÇØ´çÇÏ´Â º­¶ô ¼Ó¼ºµ¥¹ÌÁö¸¦ Ãß°¡·Î ºÎ¿©ÇÑ´Ù.";
	price = 12800;
	damage = RandomNumber(40, 70);
	PrintWeaponInfo(name, type, traits, price, damage);

	//TODO -  ¹æ¾î±¸ ±×·¡ÇÈ ÀÛ¼º
	cout << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡á¡¡¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡á¡¡¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡á¡á¡á¡¡¡¡¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡" << endl;
	name = "ÆÐÄ¡ÀÇ °©¿Ê";
	type = "°¡Á× °©¿Ê";
	traits = "¼Ò¸®¸¦ Á×ÀÌ°í, ¾îµÒ¿¡ ¼û±â À§ÇÑ °Í. Àº½Å ¹üÀ§¸¦ 1Ä­ ´Ã·ÁÁØ´Ù.";
	price = 8000;
	armour = RandomNumber(5, 10);
	PrintArmouryInfo(name, type, traits, price, armour);

	name = "Çã¼ö¾ÆºñÀÇ ³Õ¸¶";
	type = "Ãµ °©¿Ê";
	traits = "ÇÇ°Ý½Ã Âø¿ëÀÚ¿¡°Ô ¸Å¿ì ³·Àº È®·ü·Î Áßµ¶ »óÅÂÀÌ»óÀ» ¹ß»ý½ÃÅ²´Ù.";
	price = 4500;
	armour = RandomNumber(0, 7);
	PrintArmouryInfo(name, type, traits, price, armour);

}

unsigned short RandomNumber(unsigned short min, unsigned short max)
{
	//·£´ýÇÑ °ªÀ» ´ãÀ» º¯¼ö ¼±¾ð
	unsigned short randomNumber;

	//·£´ý ½Ãµå
	srand(time(NULL));

	//·£´ýÀ¸·Î »ý¼ºµÈ ¼ýÀÚ ÇÒ´ç
	randomNumber = rand() % (max - min + 1) + min;

	return randomNumber;
}

void PrintWeaponInfo(string name, string type, string traits, unsigned short price, unsigned short damage)
{
	cout << endl;
	cout << " = ============================================================================ = " << endl;
	cout << "ÀÌ¸§ : " << name << endl;
	cout << "Á¾·ù : " << type << endl;
	cout << "µ¥¹ÌÁö : " << damage << endl;
	cout << "°¡°Ý : " << price << endl;
	cout << "Æ¯¼º : " << traits << endl;
	cout << " = ============================================================================ = " << endl;
}

void PrintArmouryInfo(string name, string type, string traits, unsigned short price, unsigned short armour)
{
	cout << endl;
	cout << " = ============================================================================ = " << endl;
	cout << "ÀÌ¸§ : " << name << endl;
	cout << "Á¾·ù : " << type << endl;
	cout << "¹æ¾î·Â : " << armour << endl;
	cout << "°¡°Ý : " << price << endl;
	cout << "Æ¯¼º : " << traits << endl;
	cout << " = ============================================================================ = " << endl;
}