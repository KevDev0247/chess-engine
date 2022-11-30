#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include "player.h"

class Computer : public Player {
public:
    Computer(Board *board) : Player{board} {};
    bool baseCheckLevelTwo(Move move);
    bool baseCheckLevelThree(Move move);
    virtual Move getMove() = 0;
};

#endif
