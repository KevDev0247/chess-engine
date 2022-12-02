#ifndef LEVELTHREE_H
#define LEVELTHREE_H
#include <iostream>
#include "computer.h"
#include "move.h"
#include "board.h"

class LevelThree : public Computer {
    public:
        LevelThree(Board *board) : Computer{board} {};

        Move getMove();
};

#endif
