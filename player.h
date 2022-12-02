#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "move.h"
#include "board.h"

class Board;

class Player {
protected:
    Board *board;
public:
    Player(Board *board);
};

#endif
