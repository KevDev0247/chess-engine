#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include "player.h"

class Computer : public Player {
public:
    Computer(Board *board) : Player{board} {};
    Board* getBoard();
    bool baseCheckLevelTwo(Board boardClass, Move move);
    bool baseCheckLevelThree(Board boardClass, Move move);
    virtual Move getMove(Board board) = 0;
};

#endif
