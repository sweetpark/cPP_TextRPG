#include "pch.h"
#include "Monster.h"
#include "Player.h"

void Monster::Attack(Player* player)
{
	int realAttack = _attack - player->_def;
	if (realAttack <= 0)
	{
		cout << "몬스터가 플레이어를 공격~ ->  MISS " << endl;
	}
	else
	{
		player->_hp -= realAttack;
		if (player->_hp <= 0)
			player->_hp = 0;
		cout << "몬스터가 플레이어를 공격~ -> " << realAttack << endl;
	}
}