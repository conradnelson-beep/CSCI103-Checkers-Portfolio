#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"

class Player{
public: 
    virtual ~Player(){}
    virtual void make_move(Board& board)=0;
    virtual bool is_p1() const=0;
    
};

class HumanPlayer1:public Player{
    void make_move(Board& board) override;
    bool is_p1() const override{return true;}
    
};

class HumanPlayer2:public Player{
    void make_move(Board& board) override;
    bool is_p1() const override{return false;}
    
};

// class RandomPlayer:public Player{

// };

#endif 
