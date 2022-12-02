#ifndef DISPLAY_H
#define DISPLAY_H
#include "board.h"

class Board;

class Display {
protected:
    Board *board;
public:
    Display(Board *board);
    virtual void notify();
    virtual ~Display() {};
};

#endif