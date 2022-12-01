#include "pieceMoveGen.h"
using namespace std;

vector<Move> PieceMoveGen::getMoves() {
    return next->getMoves();
}

PieceMoveGen::~PieceMoveGen() { delete next; }

vector<Move> KingMoveGen::getMoves() {
  vector<Move> result = next->getMoves();
  
}