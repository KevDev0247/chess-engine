#ifndef MOVE_H
#define MOVE_H
#include <iostream>

class Move {
    int originSquareX;
    int originSquareY;
    int dstSqaureX;
    int dstSqaureY;

    public:
        Move(int originSquareX, int originSquareY, int dstSqaureX, int dstSqaureY);

        std::string getString();
};

#endif
