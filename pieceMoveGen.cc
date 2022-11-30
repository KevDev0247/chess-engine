#include "pieceMoveGen.h"
using namespace std;

PieceMoveGen::PieceMoveGen(MoveGen *prev) : MoveGen{*prev}, prev{prev} {}

vector<Move> PieceMoveGen::getMove(Board board, bool whitePlaying) {
    
}

PieceMoveGen::~PieceMoveGen() { delete prev; }
