#include "pieceMoveGen.h"
using namespace std;

PieceMoveGen::PieceMoveGen(MoveGen *prev) : MoveGen{*prev}, prev{prev} {}

vector<Move> PieceMoveGen::getMoves(Board board, bool whitePlaying) {
    
}

PieceMoveGen::~PieceMoveGen() { delete prev; }
