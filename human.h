#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include "player.h"

class Human : Player {
    public:
        Human();

        bool checkValidity(Board board, Move move);
};

#endif
