#pragma once
class Player;

class Monster
{
public:

	Monster(int hp, int attack, int def) : _hp(hp), _attack(attack), _def(def)
	{

	}
	virtual ~Monster()
	{

	}

	void Attack(Player* player);


public:
	int _hp;
	int _attack;
	int _def;
};

class Skel : public Monster
{
public:
	Skel() : Monster(35,8,3)
	{
		cout << "�ذ� ������.... (HP : 35 / ATT : 8 / DEF : 3)" << endl;
	}
	~Skel()
	{
		cout << "�ذ��� óġ�߽��ϴ�!" << endl;
	}
};

class Org : public Monster
{
public:
	Org() : Monster(50, 10, 5)
	{
		cout << "���� ������.... (HP : 50 / ATT : 10 / DEF : 5)" << endl;
	}
	~Org()
	{
		cout << "���Ÿ� óġ�߽��ϴ�!" << endl;
	}

};

class MagicMonster : public Monster
{
public:
	MagicMonster() : Monster(30, 15, 0)
	{
		cout << "�������� ������.... (HP : 30 / ATT : 15 / DEF : 0)" << endl;
	}
	~MagicMonster()
	{
		cout << "�������͸� óġ�߽��ϴ�!" << endl;
	}

};