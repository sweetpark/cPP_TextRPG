#include "pch.h"
#include "Player.h"
#include "Monster.h"


void Player::Attack(Monster* monster)
{
	int realAttack = _attack - monster->_def;
	if (realAttack < 0)
	{
		cout << "플레이어가 몬스터를 공격~ ->  MISS " << endl;
	}
	else
	{
		monster->_hp -= realAttack;
		if (monster->_hp <= 0)
			monster->_hp = 0;
		cout << "플레이어가 몬스터를 공격~ -> " << realAttack << endl;
	}
}


