#include "levelOne.h"
#include "pieceMoveGen.h"
using namespace std;

Move LevelOne::getMove() {
    vector<Move> moves = board->getMoves();
    
    vector<Move> levelOneMoves;
    for (auto move : moves) {
        if (baseCheckValidity(move)) levelOneMoves.push_back(move);
    }
    return levelOneMoves.front();
}
