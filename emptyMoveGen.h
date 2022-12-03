#ifndef EMPTYMOVEGEN_H
#define EMPTYMOVEGEN_H
#include "moveGen.h"
#include "board.h"
#include <iostream>

class EmptyMoveGen: public MoveGen {
    public:
        EmptyMoveGen(Board *board) : MoveGen{board} {};

        std::vector<Move> getMoves();
};

#endif
