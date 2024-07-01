#include "pch.h"
#include "Player.h"
#include "Monster.h"


void Player::Attack(Monster* monster)
{
	int realAttack = _attack - monster->_def;
	if (realAttack < 0)
	{
		cout << "�÷��̾ ���͸� ����~ ->  MISS " << endl;
	}
	else
	{
		monster->_hp -= realAttack;
		if (monster->_hp <= 0)
			monster->_hp = 0;
		cout << "�÷��̾ ���͸� ����~ -> " << realAttack << endl;
	}
}


