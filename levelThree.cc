#include "levelThree.h"
#include "pieceMoveGen.h"
using namespace std;

Move LevelThree::getMove() {
    vector<Move> moves = board->getMoves();

    vector<Move> levelThreeMoves;
    for (auto move : moves) {
        if (board->baseCheckValidity(move) && baseCheckLevelTwo(move) && baseCheckLevelThree(move)) 
            return move;
    }
    return moves.front();
}
