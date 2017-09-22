//
//  GameBoard.cpp
//

#include "GameBoard.hpp"

void GameBoard::buildBoard() {
	squares.insert(0, 0);
   for (int i = 1; i < BOARD_SIZE; i++)
   {
	   squares.insert(i, checkChutesLadders(i));
   } 
}
