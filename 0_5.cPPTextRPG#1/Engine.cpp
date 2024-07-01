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
		cout << "(0) ��� (1) �ü� (2) ����" << endl << "> ";
		cin >> input;

		if (input >= 0 || input < 3)
		{
			JobType = input;
			break;
		}
		cout << endl;
		cout << "�ٽ� �Է����ּ���" << endl;
	}

	Player* player = nullptr;  // ������ �ʱ�ȭ

	switch (JobType)
	{
	case static_cast<int>(JOBTYPE::KNIGHT):
		cout << "��簡 ������..." << endl;
		player = new Knight();
		FieldChoice(player);
		break;
	case static_cast<int>(JOBTYPE::ARROW):
		cout << "�ü��� ������..." << endl;
		player = new Arrow();
		FieldChoice(player);
		break;
	case static_cast<int>(JOBTYPE::MAGIC):
		cout << "�����簡 ������..." << endl;
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
	cout << "(0) �ʵ����� (1) ��������" << endl << "> ";
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

// ���� or ����
void Engine::WarChoice(Player* player)
{
	cout << "========================" << endl;
	cout << "�ʵ忡 �����Ͽ����ϴ�" << endl;
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
		cout << "(0) ���� (1) ����" << endl << "> ";
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
			cout << "�ٽ� �Է����ּ���" << endl;
			continue;
		}

	}
	
	cout << "�÷��̾ ����߽��ϴ�." << endl;
	cout << "������ �����մϴ�." << endl;

	
}


void Engine::War(Player* player, Monster* monster)
{
	while (player->_hp != 0 && monster->_hp != 0)
	{
		player->Attack(monster);
		cout << "���� ���� ü�� : " << monster->_hp << endl;
		monster->Attack(player);
		cout << "�÷��̾� ���� ü�� : " << player->_hp << endl;
	}
	
	if (monster->_hp == 0)
	{
		delete monster;
	}

}
