#ifndef LEVELTWO_H
#define LEVELTWO_H
#include <iostream>
#include "computer.h"
#include "move.h"
#include "board.h"

class LevelTwo : Computer {
    public:
        LevelTwo(Board *board) : Computer{board} {};

        Move getMove();
};

#endif
