#include "levelTwo.h"
#include "pieceMoveGen.h"
using namespace std;

LevelTwo::LevelTwo(PieceMoveGen* moveGen) : Computer{moveGen} {}

Move LevelTwo::getMove(Board boardClass) {
    PieceMoveGen* moveGen = getMoveGen();
    vector<Move> moves = moveGen->getMoves(boardClass, boardClass.getWhitePlaying());

    vector<Move> levelTwoMoves;
    for (auto move : moves) {
        if (baseCheckValidity(boardClass, move) && baseCheckLevelTwo(boardClass, move)) 
            levelTwoMoves.push_back(move);
    }
    return levelTwoMoves.front();
}
