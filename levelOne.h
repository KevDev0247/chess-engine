#ifndef LEVELONE_H
#define LEVELONE_H
#include <iostream>
#include "computer.h"
#include "move.h"
#include "board.h"

class LevelOne : Computer {
    public:
        LevelOne();

        Move getMove(Board board);
};

#endif
