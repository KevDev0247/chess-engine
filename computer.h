#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include "player.h"

class Computer : Player {
    public:
        Computer();

        virtual Move getMove(Board board) = 0;
};

#endif
