#include "levelOne.h"
#include "pieceMoveGen.h"
using namespace std;

LevelOne::LevelOne(PieceMoveGen* moveGen) : moveGen{moveGen} {}

Move LevelOne::getMove(Board boardClass) {
    vector<Move> moves = moveGen->getMoves(boardClass, boardClass.getWhitePlaying());
    
}
