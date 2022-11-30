#ifndef PIECEMOVEGEN_H
#define PIECEMOVEGEN_H
#include <iostream>
#include <vector>
#include "move.h"
#include "board.h"
#include "moveGen.h"

class PieceMoveGen : MoveGen {
    protected:
        MoveGen *prev;
    public:
        PieceMoveGen(MoveGen *prev);
        std::vector<Move> getMove(Board board, bool whitePlaying);
        virtual ~PieceMoveGen();
};

#endif