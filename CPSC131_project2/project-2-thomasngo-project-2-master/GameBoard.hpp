//
//  GameBoard.hpp
//

#pragma once

#include <stdexcept>

#include "ExtendableVector.h"
#include <map>
#include <iterator>

const int OUTSIDE_BOARD = -1;
const int BOARD_SIZE = 101;

class GameBoard {
public:   
   enum Ladders { ONE = 1, FOUR = 4, NINE = 9, TWENTY_ONE = 21, TWENTY_EIGHT = 28, THIRTY_SIX = 36, FIFTY_ONE = 51, SEVENTY_ONE = 71, EIGHTY = 80 };
   
   enum Chutes { SIXTEEN = 16, FORTY_SEVEN = 47, FORTY_NINE = 49, FIFTY_SIX = 56, SIXTY_TWO = 62, SIXTY_FOUR = 64, EIGHTY_SEVEN = 87, NINETY_THREE = 93, NINETY_FIVE = 95, NINETY_EIGHT = 98 };
   
   // Build the gameboard
   // TO DO: implement this function
   void buildBoard();
   
   GameBoard() {
       ChutesBoard.reserve(1);		// reserving an additional square
	    buildBoard();
   }
   
   // If player lands on chutes or ladders, returns the new position.
   // Otherwise, returns the player's current position.
   // If the player's position is outside of the gameboard, throws index out of bounds exception
   // TO DO: implement this function properly
   int checkChutesLadders(int position) 
   {
      if ((position < 0) || (position >= BOARD_SIZE)) {
         throw range_error("index out of bounds");
      }
      // TODO: implement this function properly
      //throw std::logic_error("not implemented yet");
	  else
	  {
		  map<int, int> check;
		  //landing and new squares for ladders
		  check[1] = 38;
		  check[4] = 14;
		  check[9] = 31;
		  check[21] = 42;
		  check[28] = 84;
		  check[36] = 44;
		  check[51] = 67;
		  check[71] = 91;
		  check[80] = 100;

		  //landing and new squares for chutes
		  check[16] = 6;
		  check[47] = 26;
		  check[49] = 11;
		  check[56] = 53;
		  check[62] = 19;
		  check[64] = 60;
		  check[87] = 24;
		  check[93] = 73;
		  check[95] = 75;
		  check[98] = 78;

		  map<int, int>::const_iterator iter;
		  for (iter = check.begin(); iter != check.end(); iter++)
		  {
			  if (iter->first == position)
			  {
				  return iter->second;
			  }
		  }

		  return position;

	  }
   }
   
private:
   // TO DO: add storage for squares including square of chutes and ladders
   // Requirement: use ExtendableVector to store the square
   ExtendableVector<int> ChutesBoard; 
};
