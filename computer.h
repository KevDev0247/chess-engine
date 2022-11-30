#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include "player.h"
#include "pieceMoveGen.h"

class Computer : public Player {
    PieceMoveGen *moveGen;
    public:
        Computer(PieceMoveGen *moveGen);
        PieceMoveGen* getMoveGen();
        bool baseCheckLevelTwo(Board boardClass, Move move);
        bool baseCheckLevelThree(Board boardClass, Move move);
        virtual Move getMove(Board board) = 0;
};

#endif
