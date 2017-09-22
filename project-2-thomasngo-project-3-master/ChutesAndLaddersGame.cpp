//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

// constructor with the default value of a minimum players
ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") {
	
	Player newPlayer("William");
	playerList.enqueue(newPlayer);
	newPlayer.setName("Thomas");
	playerList.enqueue(newPlayer);
}

// destructor - dequeue players from the queue
ChutesAndLaddersGame::~ChutesAndLaddersGame() {
	while (!playerList.empty())
	{
		playerList.dequeue();
	}
}

void ChutesAndLaddersGame::resetGame() {
	while (!playerList.empty())
	{
		playerList.dequeue();
	}
	Player newPlayer("William");
	playerList.enqueue(newPlayer);
	newPlayer.setName("Thomas");
	playerList.enqueue(newPlayer);
}

void ChutesAndLaddersGame::playGame() {

	Player playerTurn;
	bool found = false;

	while (!found)
	{
		playerTurn = playerList.front();
		playerList.dequeue();
	
		playerTurn.setPostion(gameBoard.checkChutesLadders(playerTurn.rollDieAndMove()));
		if (playerTurn.getPostion() == WINNING_POSITION)
		{
			winner = playerTurn.getName();
			found = true;
		}
		else
			playerList.enqueue(playerTurn);
	}

	cout << "Congratulation! " << playerTurn.getName() << " win the game." << endl;
}

