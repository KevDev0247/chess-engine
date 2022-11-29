#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "move.h"

class Player {
    public:
        Player();

        // need Board
        virtual Move getMove() = 0;
};

#endif
