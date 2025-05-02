#ifndef BOARD_H
#define BOARD_H
class Board {

public:
    Board(int rows, int cols);
    ~Board();
   // void output_Board();
    void print_board();
    bool is_valid(int start_row, int start_col, int end_row, int end_col, bool p1);
    bool move_piece(int start_row, int start_col, int end_row, int end_col); 
    bool hasWon();
protected:
    int rows_;
    int cols_;
    int** board_val_array;
    int top_pieces_taken_;
    int bottom_pieces_taken_;


// for tracking if a square is empty or occupied by either player
// empty squares have value 0, a square occupied by upper team has positive value and lower has negative value
};

enum Piece{
    EMPTY=0,
    TOP_PIECE=1,
    TOP_KING=2,
    BOTTOM_PIECE=-1,
    BOTTOM_KING=-2
};

#endif

