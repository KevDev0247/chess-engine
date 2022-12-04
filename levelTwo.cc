#include "levelTwo.h"
#include "pieceMoveGen.h"
using namespace std;

Move LevelTwo::getMove() {
    srand((unsigned int)time(NULL));
    vector<Move> moves = board->getMoves();

    // push all valid moves into level 1
    vector<Move> levelOneMoves;
    for (auto move : moves) {
        if (board->checkValidity(move)) 
            levelOneMoves.push_back(move);
    }

    // push all capturing and checks moves into level 2
    // missing checks
    vector<Move> levelTwoMoves;
    for (auto move : moves) {
        if (board->checkValidity(move) && baseCheckLevelTwo(move)) 
            levelTwoMoves.push_back(move);
    }

    // if no level 2 moves available, perform level 1 moves
    if (levelTwoMoves.size() != 0) {
        int range = levelTwoMoves.size();
        int randomNum = rand() % range;
        return levelTwoMoves.at(randomNum);
    } else {
        int range = levelOneMoves.size();
        int randomNum = rand() % range;
        return levelOneMoves.at(randomNum);        
    }
}
