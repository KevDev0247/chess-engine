#include "levelOne.h"
#include "pieceMoveGen.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Move LevelOne::getMove() {
    srand((unsigned int)time(NULL));
    vector<Move> moves = board->getMoves();
    
    // push all valid moves into level 1
    vector<Move> levelOneMoves;
    for (auto move : moves) {
        if (board->baseCheckValidity(move)) 
            levelOneMoves.push_back(move);
    }
 
    // generate random number to choose in level 1 moves
    int range = levelOneMoves.size();
    int randomNum = rand() % range;

    return levelOneMoves.at(randomNum);
}
