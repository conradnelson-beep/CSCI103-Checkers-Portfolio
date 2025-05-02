#include "player.h"
#include <iostream>

using namespace std;

void HumanPlayer1::make_move(Board& board){
    int start_row, start_col, end_row, end_col;
    cout<<"player 1's turn (blue), enter move: start_row start_col end_row end_col"<<endl;
    cin>>start_row>>start_col>>end_row>>end_col;

    if(board.is_valid(start_row, start_col, end_row, end_col,true)){
        board.move_piece(start_row, start_col, end_row, end_col);}
    else{
        cout<<"invalid start, enter again"<<endl;
         make_move(board);
            }
        }
    


void HumanPlayer2::make_move(Board& board){
    int start_row, start_col, end_row, end_col;
    cout<<"player 2's turn (red), enter move: start_row start_col end_row end_col: "<<endl;
    cin>>start_row>>start_col>>end_row>>end_col;

    if(board.is_valid(start_row, start_col, end_row, end_col,false)){
        board.move_piece(start_row, start_col, end_row, end_col);}
    else{
        cout<<"invalid start, enter again"<<endl;
        make_move(board);
            }
        }
    

