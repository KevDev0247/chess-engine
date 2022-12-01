#ifndef MOVE_H
#define MOVE_H
#include <iostream>

enum MoveType {
    Normal,
    Castling,
    Promotion,
    EnPassant
};

struct Move {
    int originSquareX;
    int originSquareY;
    int dstSquareX;
    int dstSquareY;
    char promotionPiece;
    MoveType moveType;

    std::string getString() const;
};

#endif
