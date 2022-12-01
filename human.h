#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include "player.h"

class Human : public Player {
    public:
        Human(Board *board) : Player{board} {};

        bool checkValidity(Move move);
};

#endif
