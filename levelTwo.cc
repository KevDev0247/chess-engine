#include "levelTwo.h"
#include "pieceMoveGen.h"
using namespace std;

Move LevelTwo::getMove() {
    vector<Move> moves = board->getMoves();

    vector<Move> levelTwoMoves;
    for (auto move : moves) {
        if (board->baseCheckValidity(move) && baseCheckLevelTwo(move)) 
            levelTwoMoves.push_back(move);
    }
    return levelTwoMoves.front();
}
