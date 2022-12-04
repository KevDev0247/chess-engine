#include "levelTwo.h"
#include "pieceMoveGen.h"
using namespace std;

Move LevelTwo::getMove() {
    srand((unsigned int)time(NULL));
    vector<Move> moves = board->getMoves();

    vector<Move> levelOneMoves;
    for (auto move : moves) {
        if (board->baseCheckValidity(move)) 
            levelOneMoves.push_back(move);
    }

    vector<Move> levelTwoMoves;
    for (auto move : moves) {
        if (board->baseCheckValidity(move) && baseCheckLevelTwo(move)) 
            levelTwoMoves.push_back(move);
    }

    if (levelTwoMoves.size() == 0) {
        int range = levelOneMoves.size();
        int randomNum = rand() % range;
        return levelOneMoves.at(randomNum);
    } else {
        int range = levelTwoMoves.size();
        int randomNum = rand() % range;
        return levelTwoMoves.at(randomNum);
    }
}
