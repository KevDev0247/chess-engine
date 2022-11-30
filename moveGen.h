#ifndef MOVEGEN_H
#define MOVEGEN_H
#include <iostream>
#include <vector>
#include "move.h"
#include "board.h"

class MoveGen {
protected:
    Board *board;
public:
    MoveGen(Board *board) : board{board} {};

    std::vector<Move> virtual getMoves();
};

#endif