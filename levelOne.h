#ifndef LEVELONE_H
#define LEVELONE_H
#include <iostream>
#include "computer.h"
#include "move.h"
#include "board.h"
#include "pieceMoveGen.h"

class LevelOne : Computer {
    PieceMoveGen *moveGen;
    public:
        LevelOne(PieceMoveGen *moveGen);

        Move getMove(Board board);
};

#endif
