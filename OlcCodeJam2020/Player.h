#pragma once
#include <string>

class Player
{
public:
	Player();
	~Player();

	std::string name;
	float x;
	float y;
	float direction;
	bool isDead;

};

