#include "board.h"
#include <iostream>

using namespace std;

// file for implementing board functions

Board::Board(int rows, int cols) {
    // board initialization in ctor

    rows_ = rows;
    cols_ = cols; // for use in other fxns
    top_pieces_taken_ = 0;
    bottom_pieces_taken_ = 0;

    board_val_array = new int*[rows];

    for (int i = 0; i < rows; i++) {
        board_val_array[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
        
            // top 3 rows have every other square occupied by a piece from top team (value 0)
            // bottom 3 rows have every other square occupied by a piece from bottom team (value 1)

            if (i < 3) {
                if (i != 1 && j % 2 == 0) {
                // for rows 0,2 every even square (top team pieces)
                    board_val_array[i][j] = TOP_PIECE;
                    
                }
                else if (i == 1 && j % 2 == 1) {
                // for row 1 should be staggered
                    board_val_array[i][j] = TOP_PIECE;
                    

                }
            }
            else if (rows - i < 4) {
                if (rows - i != 2 && j % 2 == 1) {
                    // for bottom & 3rd from bottom row 
                    board_val_array[i][j] = BOTTOM_PIECE;
                    
                }
                else if(rows - i == 2 && j % 2 == 0) {
                    board_val_array[i][j] = BOTTOM_PIECE;
                   
                }
            }
           
            else {
                // sets all non-occupied square values to 0 (empty)
                board_val_array[i][j] = EMPTY;
            }
        }
    }


}
// replaced w/ operator overload

// void Board::output_Board() {
//     for (int i = 0; i < rows_; i++) {
//         for (int j = 0; j < cols_; j++) {
//             cout << board_val_array[i][j];
//         }
//         cout << endl;
//     }
// }

 void Board::print_board() {
    cout << "  0 1 2 3 4 5 6 7" << endl; // for easy reading
    for(int i = 0; i < rows_; i++) {
        cout<< i; // for easy reading
        for (int j = 0; j < cols_; j++) {
            if(board_val_array[i][j] == TOP_PIECE) {
                // note: can change the pieces later, but I just wanted to make the pieces equal size to the empty board squares
                // so it generates evenly 
                cout << "🔵"; // ⛀
            }
            else if (board_val_array[i][j] == TOP_KING) {
                cout << "🟢"; // ⛁
            }
            else if(board_val_array[i][j] == BOTTOM_PIECE) {
                cout << "🔴"; // ⛂
            }
            else if(board_val_array[i][j] == BOTTOM_KING) {
                cout << "🟠"; // ⛃
            }
            else if (board_val_array[i][j] == EMPTY && j%2 == 0) {
                cout << "⬜"; // ⬜
            }
            else if (board_val_array[i][j] == EMPTY && j%2 == 1) {
                cout << "⬛"; // ⬛
            }
        }
        cout << endl;
    }
}

Board::~Board() {
    for(int i = 0; i < rows_; i++){
        delete [] board_val_array[i];
    }
    delete [] board_val_array;
}

bool Board::is_valid(int start_row, int start_col, int end_row, int end_col, bool p1){
    if (board_val_array[start_row][start_col] == EMPTY || board_val_array[end_row][end_col] != EMPTY || 
        abs(start_row - end_row)>2  || abs(start_col - end_col)>2 ){
            return false;
        }
    return true;
}

bool Board::move_piece(int start_row, int start_col, int end_row, int end_col){
    while (true){
    if (start_row < 0 || start_row >= rows_ || start_col < 0 || start_col >= cols_ ||
        end_row < 0 || end_row >= rows_ || end_col < 0 || end_col >= cols_ || 
        board_val_array[start_row][start_col] == EMPTY || board_val_array[end_row][end_col] != EMPTY || 
        abs(start_row - end_row) > 2 || abs(start_col - end_col) >2 ||
        (board_val_array[start_row][start_col] == TOP_PIECE && end_row < start_row) || (board_val_array[start_row][start_col] == BOTTOM_PIECE && end_row > start_row)) {
        
        cout << "invalid move! try again:" << endl;
        cin >> start_row >> start_col >> end_row >> end_col;
    }
    else if(abs(start_row - end_row) == 1 && abs(start_col - end_col) == 1) {
    board_val_array[end_row][end_col]=board_val_array[start_row][start_col];
    board_val_array[start_row][start_col]=EMPTY;
    return true;
        }
    else if(abs(start_row - end_row) == 2 && abs(start_col - end_col) == 2){
        int row_diff = end_row - start_row;
        int col_diff = end_col - start_col; 
        int mid_row = start_row + row_diff / 2;
        int mid_col = start_col + col_diff / 2;
        int mid_piece = board_val_array[mid_row][mid_col];
        if ((board_val_array[start_row][start_col] == TOP_PIECE && mid_piece == BOTTOM_PIECE) || 
            (board_val_array[start_row][start_col] == BOTTOM_PIECE && mid_piece == TOP_PIECE)) {
                board_val_array[end_row][end_col] = board_val_array[start_row][start_col];
                board_val_array[mid_row][mid_col] = EMPTY; 
                board_val_array[start_row][start_col] = EMPTY;
                if (mid_piece==TOP_PIECE){
                    top_pieces_taken_++;
                }
                else if (mid_piece==BOTTOM_PIECE){
                    bottom_pieces_taken_++;
                }
                cout << "piece captured!" << endl;
                return true;
            }
        else {
                cout << "no opponent piece to jump over, try again:" << endl;
                cin >> start_row >> start_col >> end_row >> end_col;
                continue;
                }
        }

    }
    return false;
}



