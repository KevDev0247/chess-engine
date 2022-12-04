#ifndef PIECEMOVEGEN_H
#define PIECEMOVEGEN_H
#include <iostream>
#include <vector>
#include "move.h"
#include "board.h"
#include "moveGen.h"

using namespace std;

class PieceMoveGen : public MoveGen {
protected:
    MoveGen *next;
public:
    PieceMoveGen(MoveGen* next, Board *board) : next{next}, MoveGen{board} {};
    virtual std::vector<Move> getMoves(bool simulateCheck);
    virtual ~PieceMoveGen();
};

class KnightMoveGen : public PieceMoveGen {
    using PieceMoveGen::PieceMoveGen;
    std::vector<Move> getMoves(bool simulateCheck) override;
};

class KingMoveGen : public PieceMoveGen {
    using PieceMoveGen::PieceMoveGen;
    std::vector<Move> getMoves(bool simulateCheck) override;
};

class PawnMoveGen : public PieceMoveGen {
    using PieceMoveGen::PieceMoveGen;
    std::vector<Move> getMoves(bool simulateCheck) override;
};


class RookMoveGen : public PieceMoveGen {
    using PieceMoveGen::PieceMoveGen;
    std::vector<Move> getMoves(bool simulateCheck) override;
};


class BishopMoveGen : public PieceMoveGen {
    using PieceMoveGen::PieceMoveGen;
    std::vector<Move> getMoves(bool simulateCheck) override;
};


class QueenMoveGen : public PieceMoveGen {
    using PieceMoveGen::PieceMoveGen;
    std::vector<Move> getMoves(bool simulateCheck) override;
};

void genRookMoves(
  vector<vector<char>> &boardArray,
  int y,
  int x,
  vector<Move> &result
);

void genBishopMoves(
  vector<vector<char>> &boardArray,
  int y,
  int x,
  vector<Move> &result
);

#endif