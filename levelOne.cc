#include "levelOne.h"
#include "pieceMoveGen.h"
using namespace std;

LevelOne::LevelOne(PieceMoveGen* moveGen) : Computer{moveGen} {}

Move LevelOne::getMove(Board boardClass) {
    PieceMoveGen* moveGen = getMoveGen();
    vector<Move> moves = moveGen->getMoves(boardClass, boardClass.getWhitePlaying());
    
    vector<Move> levelOneMoves;
    for (auto move : moves) {
        if (baseCheckValidity(boardClass, move)) levelOneMoves.push_back(move);
    }
    return levelOneMoves.front();
}
