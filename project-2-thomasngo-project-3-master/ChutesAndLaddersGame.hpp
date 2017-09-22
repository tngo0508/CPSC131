//
//  ChutesAndLaddersGame.hpp
//

#pragma once

#include <stdio.h>
#include <string>

#include "ArrayQueue.h"
#include "Player.hpp"
#include "GameBoard.hpp"

using namespace std;


const int MIN_NUMBER_OF_PLAYERS = 2;

class ChutesAndLaddersGame {
public:
	ChutesAndLaddersGame(int nPlayers = MIN_NUMBER_OF_PLAYERS);

	// destructor
	~ChutesAndLaddersGame();

	// accessors
	int getNumberOfPlayers() {
		return MIN_NUMBER_OF_PLAYERS;
	}
	string getWinner() { return winner; }

	void resetGame();

	void playGame();
private:
	const int WINNING_POSITION = 100;

	string winner;       // the winner
	GameBoard gameBoard; // the game board

	ArrayQueue<Player> playerList;
};
