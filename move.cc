#include "move.h"

Move::Move(
  int originSquareX,
  int originSquareY,
  int dstSquareX,
  int dstSquareY,
  char promotionPiece,
  char piece,
  MoveType moveType
) : originSquareX{originSquareX}, originSquareY{originSquareY},
dstSquareX{dstSquareX}, dstSquareY{dstSquareY}, promotionPiece{promotionPiece},
piece{piece}, moveType{moveType} {}