//
//  Player.cpp
//

#include "Player.hpp"

Player& Player::operator=(const Player& p) {
	if (this != &p)
	{
		playerName = p.playerName;
		position = p.position;
		die = p.die;
	}
	return *this;
}

int Player::rollDieAndMove() {
	this->die.roll();
	int newPosition = position + die.getFaceValue();
	if (newPosition > (BOARD_SIZE - 1))
	{
		return position;
	}
	else
		return newPosition;
}
