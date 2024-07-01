#pragma once

class Monster;

class Player
{
public:
	Player(int hp, int attack, int def) : _hp(hp), _attack(attack), _def(def)
	{
	}
	virtual ~Player()
	{
	}

	void Attack(Monster* monster);
	void PlayerInfo()
	{
		cout << "Player HP: " << _hp << " ATT : " << _attack << " DEF : " << _def << endl;
	}

public:
	int _hp;
	int _attack;
	int _def;

};


class Knight : public Player
{
public:
	Knight() : Player(100, 15, 10)
	{
	}
	~Knight()
	{
	}

};


class Arrow : public Player
{
public:
	Arrow() : Player(100, 20, 5)
	{
	}
	~Arrow()
	{
	}

};

class Magic : public Player
{
public:
	Magic() : Player(100, 25, 0)
	{
	}
	~Magic()
	{
	}

};
