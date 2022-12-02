#include "human.h"
#include "player.h"
#include "algorithm"
#include <vector>
using namespace std;

bool Human::checkValidity(Move move) {
    vector<Move> validMoves = board->getMoves();
    for (int i = 0; i < validMoves.size(); i++) {
        Move curr = validMoves.at(i);
        if (curr.dstSquareX == move.dstSquareX &&
            curr.dstSquareY == move.dstSquareY &&
            curr.moveType == move.moveType &&
            curr.originSquareX == move.originSquareY &&
            curr.piece == move.piece &&
            curr.promotionPiece == move.promotionPiece) 
            return true;
    }
    return false;
}

 