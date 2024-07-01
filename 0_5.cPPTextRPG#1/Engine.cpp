#include "pch.h"
#include "Engine.h"
#include "Monster.h"
#include "Player.h"

void Engine::JobChoice()
{
	while (true)
	{
		int input;
		cout << "======================" << endl;
		cout << "(0) 기사 (1) 궁수 (2) 법사" << endl << "> ";
		cin >> input;

		if (input >= 0 || input < 3)
		{
			JobType = input;
			break;
		}
		cout << endl;
		cout << "다시 입력해주세요" << endl;
	}

	Player* player = nullptr;  // 포인터 초기화

	switch (JobType)
	{
	case static_cast<int>(JOBTYPE::KNIGHT):
		cout << "기사가 생성중..." << endl;
		player = new Knight();
		FieldChoice(player);
		break;
	case static_cast<int>(JOBTYPE::ARROW):
		cout << "궁수가 생성중..." << endl;
		player = new Arrow();
		FieldChoice(player);
		break;
	case static_cast<int>(JOBTYPE::MAGIC):
		cout << "마법사가 생성중..." << endl;
		player = new Magic();
		FieldChoice(player);
		break;

	}

	delete player;

}


void Engine::FieldChoice(Player* player)
{
	int input;
	cout << "-----------------------------" << endl;
	cout << "(0) 필드입장 (1) 게임종료" << endl << "> ";
	cin >> input;

	switch (input)
	{
	case FIELD:
		WarChoice(player);
		break;
	case EXIT:
		return;
		break;
	}

}

// 전투 or 도주
void Engine::WarChoice(Player* player)
{
	cout << "========================" << endl;
	cout << "필드에 입장하였습니다" << endl;
	cout << "========================" << endl;
	
	while (player->_hp != 0)
	{
		srand(static_cast<unsigned int>(time(nullptr)));

		int random = rand() % 3;
		Monster* monster = nullptr;

		cout << "==========================" << endl;
		player->PlayerInfo();
		switch (random)
		{
		case static_cast<int>(MONSTER::SKEL):
			monster = new Skel();
			break;
		case static_cast<int>(MONSTER::ORG):
			monster = new Org();
			break;
		case static_cast<int>(MONSTER::MAGIC):
			monster = new MagicMonster();
			break;
		}
		

		int input;
		cout << "==========================" << endl;
		cout << "(0) 전투 (1) 도주" << endl << "> ";
		cin >> input;

		if (input >= 0 && input < 2)
		{
			switch (input)
			{
			case WAR:
				War(player, monster);
				break;
			case RUN:
				break;
			}
		}
		else
		{
			cout << "다시 입력해주세요" << endl;
			continue;
		}

	}
	
	cout << "플레이어가 사망했습니다." << endl;
	cout << "게임을 종료합니다." << endl;

	
}


void Engine::War(Player* player, Monster* monster)
{
	while (player->_hp != 0 && monster->_hp != 0)
	{
		player->Attack(monster);
		cout << "몬스터 남은 체력 : " << monster->_hp << endl;
		monster->Attack(player);
		cout << "플레이어 남은 체력 : " << player->_hp << endl;
	}
	
	if (monster->_hp == 0)
	{
		delete monster;
	}

}
