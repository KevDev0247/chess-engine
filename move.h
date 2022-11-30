#ifndef MOVE_H
#define MOVE_H
#include <iostream>

class Move {
    int originSquareX;
    int originSquareY;
    int dstSqaureX;
    int dstSqaureY;
    char piece;

    public:
        Move(int originSquareX, int originSquareY, int dstSqaureX, int dstSqaureY, char piece);

        std::string getString();
        int getDstSquareX();
        int getDstSquareY();
        int getOriginSquareX();
        int getOriginSquareY();
        char getPiece();
};

#endif
