#pragma once
class Player;
class Monster;

class Engine
{
public:
	void JobChoice();
	void FieldChoice(Player *player);
	void WarChoice(Player* player);

	void War(Player* player, Monster* monster);

public:
	int JobType;

};


