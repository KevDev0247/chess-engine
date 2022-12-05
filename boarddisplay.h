#ifndef DISPLAY_H
#define DISPLAY_H
#include "board.h"

class Board;

class BoardDisplay {
protected:
    Board *board;
public:
    BoardDisplay(Board *board) : board{board} {};
    virtual void notify() {};
    virtual ~BoardDisplay() {};
};

#endif
