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
		cout << "해골 생성중.... (HP : 35 / ATT : 8 / DEF : 3)" << endl;
	}
	~Skel()
	{
		cout << "해골을 처치했습니다!" << endl;
	}
};

class Org : public Monster
{
public:
	Org() : Monster(50, 10, 5)
	{
		cout << "오거 생성중.... (HP : 50 / ATT : 10 / DEF : 5)" << endl;
	}
	~Org()
	{
		cout << "오거를 처치했습니다!" << endl;
	}

};

class MagicMonster : public Monster
{
public:
	MagicMonster() : Monster(30, 15, 0)
	{
		cout << "마법몬스터 생성중.... (HP : 30 / ATT : 15 / DEF : 0)" << endl;
	}
	~MagicMonster()
	{
		cout << "마법몬스터를 처치했습니다!" << endl;
	}

};