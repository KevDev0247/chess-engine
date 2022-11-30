#ifndef DISPLAY_H
#define DISPLAY_H
#include "board.h"

class Display {
    Board *board;

    void notify();
};

#endif