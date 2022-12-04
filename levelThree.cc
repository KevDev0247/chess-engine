#include "levelThree.h"
#include "pieceMoveGen.h"
using namespace std;

Move LevelThree::getMove() {
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

    vector<Move> levelThreeMoves;
    for (auto move : moves) {
        if (board->baseCheckValidity(move) && baseCheckLevelTwo(move) && baseCheckLevelThree(move)) 
            levelThreeMoves.push_back(move);
    }

    if (levelThreeMoves.size() != 0) {
        int range = levelThreeMoves.size();
        int randomNum = rand() % range;
        return levelThreeMoves.at(randomNum);
    } else if (levelTwoMoves.size() != 0) {
        int range = levelTwoMoves.size();
        int randomNum = rand() % range;
        return levelTwoMoves.at(randomNum);
    } else {
        int range = levelOneMoves.size();
        int randomNum = rand() % range;
        return levelOneMoves.at(randomNum);      
    }
}
