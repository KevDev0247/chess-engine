#ifndef PIECEMOVEGEN_H
#define PIECEMOVEGEN_H
#include <iostream>
#include <vector>
#include "move.h"
#include "board.h"
#include "moveGen.h"

class PieceMoveGen : public MoveGen {
protected:
    MoveGen *next;
public:
    PieceMoveGen(MoveGen* next, Board *board) : next{next}, MoveGen{board} {};
    virtual std::vector<Move> getMoves();
    virtual ~PieceMoveGen();
};

class KingMoveGen : public PieceMoveGen {
    using PieceMoveGen::PieceMoveGen;
    std::vector<Move> getMoves() override;
};

#endif