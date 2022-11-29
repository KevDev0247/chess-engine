#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include "player.h"

class Human : Player {
    public:
        Human();

        Move getMove();
};

#endif
