// this file will be for implementing player and AI movement/turn taking
#include<iostream>
#include "board.h"

using namespace std; 

bool Board::hasWon() {
  
  if (top_pieces_taken_ == 3) {
    cout << "Red (Bottom) Team Wins!" << endl;
    return true;
  }
  else if (bottom_pieces_taken_ == 3) {
    cout << "Blue (Top) Team Wins!" << endl;
    return true;
  }
  else {
    cout << "Nobody won yet" << endl;
    return false;
  }
}
