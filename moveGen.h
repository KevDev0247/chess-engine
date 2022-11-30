#ifndef MOVEGEN_H
#define MOVEGEN_H
#include <iostream>
#include <vector>
#include "move.h"
#include "board.h"

class MoveGen {
    public:
        MoveGen();

        std::vector<Move> getMove(Board board, bool whitePlaying);
};

#endif