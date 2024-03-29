#include "human.h"
#include "player.h"
#include "algorithm"
#include <vector>
using namespace std;

bool Human::checkValidity(Move move) {
    vector<Move> validMoves;
    vector<Move> boardMoves = board->getMoves();
    for (auto boardMove: boardMoves) {
        if (board->checkValidity(boardMove)) 
            validMoves.push_back(boardMove);
    }
    for (int i = 0; i < validMoves.size(); i++) {
        Move curr = validMoves.at(i);
        // if a move is among the valid moves generated, it is valid
        if (curr.dstSquareX == move.dstSquareX &&
            curr.dstSquareY == move.dstSquareY &&
            curr.moveType == move.moveType &&
            curr.originSquareX == move.originSquareX &&
            curr.originSquareY == move.originSquareY &&
            curr.piece == move.piece) 
            return true;
    }
    return false;
}
