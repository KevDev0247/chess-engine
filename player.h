#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "move.h"
#include "board.h"

class Player {
    public:
        Player();

        // need Board
        virtual Move getMove(Board board) = 0;
};

#endif
