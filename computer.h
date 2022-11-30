#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include "player.h"

class Computer : Player {
    public:
        Computer();

        Move getMove(Board board);
};

#endif
