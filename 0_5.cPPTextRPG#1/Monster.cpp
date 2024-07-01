#include "pch.h"
#include "Monster.h"
#include "Player.h"

void Monster::Attack(Player* player)
{
	int realAttack = _attack - player->_def;
	if (realAttack <= 0)
	{
		cout << "���Ͱ� �÷��̾ ����~ ->  MISS " << endl;
	}
	else
	{
		player->_hp -= realAttack;
		if (player->_hp <= 0)
			player->_hp = 0;
		cout << "���Ͱ� �÷��̾ ����~ -> " << realAttack << endl;
	}
}