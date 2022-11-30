#include "board.h"
#include "pieceMoveGen.h"

Board::Board() {}

void Board::setPieceMoveGen(PieceMoveGen *moveGen) {
    this->moveGen = moveGen;
}

std::vector<Move> Board::getMoves() {
    return moveGen->getMoves();
}

std::vector<std::vector<char>> Board::getBoard() {
    return board;
}

bool Board::getWhitePlaying() {
    return whitePlaying;
}
