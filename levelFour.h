#ifndef LEVELFOUR_H
#define LEVELFOUR_H
#include <iostream>
#include "computer.h"
#include "move.h"
#include "board.h"

class LevelFour : Computer {
    public:
        LevelFour(Board *board) : Computer{board} {};

        Move getMove();
};

#endif
