#ifndef DISPLAY_H
#define DISPLAY_H
#include "board.h"

class Display {
protected:
    Board *board;
public:
    Display(Board *board) : board{board} {};
    virtual void notify();
    virtual ~Display();
};

#endif