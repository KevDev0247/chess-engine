#include "levelThree.h"
#include "pieceMoveGen.h"
using namespace std;

Move LevelThree::getMove() {
    srand((unsigned int)time(NULL));
    vector<Move> moves = board->getMoves();

    // push all valid moves into level 1
    vector<Move> levelOneMoves;
    for (auto move : moves) {
        if (board->baseCheckValidity(move)) 
            levelOneMoves.push_back(move);
    }

    // push all capturing and checks moves into level 2
    vector<Move> levelTwoMoves;
    for (auto move : moves) {
        if (board->baseCheckValidity(move) && baseCheckLevelTwo(move)) 
            levelTwoMoves.push_back(move);
    }

    // push all avoiding capture and checks moves into level 2
    // missing avoid checks
    vector<Move> levelThreeMoves;
    for (auto move : moves) {
        if (board->baseCheckValidity(move) && baseCheckLevelTwo(move) && baseCheckLevelThree(move)) 
            levelThreeMoves.push_back(move);
    }

    // if no level 3 moves available, perform level 2 moves
    // if no level 2 moves available, perform level 1 moves
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
