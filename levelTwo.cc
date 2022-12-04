#include "levelTwo.h"
#include "pieceMoveGen.h"
using namespace std;

Move LevelTwo::getMove() {
    vector<Move> moves = board->getMoves();

    // at the start of the game, shud use level one moves

    vector<Move> levelTwoMoves;
    for (auto move : moves) {
        if (board->baseCheckValidity(move) && baseCheckLevelTwo(move)) 
            levelTwoMoves.push_back(move);
    }
    cout << levelTwoMoves.size() << endl;
    return levelTwoMoves.front();
}
