#ifndef LEVELTHREE_H
#define LEVELTHREE_H
#include <iostream>
#include "computer.h"
#include "move.h"
#include "board.h"

class LevelThree : Computer {
    public:
        LevelThree();

        Move getMove(Board board);
};

#endif
