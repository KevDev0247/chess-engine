#ifndef LEVELTWO_H
#define LEVELTWO_H
#include <iostream>
#include "computer.h"
#include "move.h"
#include "board.h"

class LevelTwo : Computer {
    public:
        LevelTwo(PieceMoveGen* moveGen);

        Move getMove(Board board);
};

#endif
