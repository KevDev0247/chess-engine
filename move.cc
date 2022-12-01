#include "move.h"

Move::Move(
  int originSquareX,
  int originSquareY,
  int dstSquareX,
  int dstSquareY,
  char promotionPiece,
  MoveType moveType
) : originSquareX{originSquareX}, originSquareY{originSquareY},
dstSquareX{dstSquareX}, dstSquareY{dstSquareY}, promotionPiece{promotionPiece},
moveType{moveType} {}