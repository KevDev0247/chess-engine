#include "move.h"

Move::Move(int originSquareX, int originSquareY, int dstSqaureX, int dstSqaureY, char move) :
    originSquareX{originSquareX}, originSquareY{originSquareY}, dstSqaureX{dstSqaureX}, dstSqaureY{dstSqaureY}, piece{piece} {}

int Move::getDstSquareX() {
    return dstSqaureX;
}

int Move::getDstSquareY() {
    return dstSqaureY;
}

int Move::getOriginSquareX() {
    return originSquareX;
}

int Move::getOriginSquareY() {
    return originSquareY;
}

char Move::getPiece() {
    return piece;
}
