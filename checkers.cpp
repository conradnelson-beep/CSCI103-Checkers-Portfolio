#include<iostream>
#include "board.h"
#include "player.h"
using namespace std;


int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << argv[0] << " <number_of_rows> <number_of_columns>" << endl;
        cout << "Example: " << argv[0] << " 8 8" << endl;
        cout << "Insufficient arguments" << endl;
        return 1; 
      
        }

int rows = atoi(argv[1]);
int cols = atoi(argv[2]);

if(atoi(argv[1]) < 8 || atoi(argv[2]) < 8) {
    cout << "Minimum size for either dimension is 8" << endl;
    return 1;
}
else if( atoi(argv[1]) % 2 != 0 || atoi(argv[2]) % 2 != 0) {
    cout << "Board dimensions must be even (divisible by 2)" << endl;
    return 1;
}
Board b(atoi(argv[1]),atoi(argv[2]));

b.print_board(); // for debugging (works successfully)
cout << "First team to take 3 pieces wins" << endl;
HumanPlayer1 p1;
HumanPlayer2 p2;

Player* current=&p1;

while(true)
{
    current->make_move(b);
    b.print_board();
    if(current==&p1){
        current=&p2;
    } else{
        current=&p1;
    }
    if(b.hasWon()) {
        cout << "Game Over" << endl;
        break;
    }
}


return 0;

    }



