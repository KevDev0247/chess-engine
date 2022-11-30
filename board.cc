#include "board.h"

Board::Board() {}

void Board::setPieceMoveGen(PieceMoveGen *moveGen) {
    this->moveGen = moveGen;
}

std::vector<std::vector<char>> Board::getBoard() {
    return board;
}

bool Board::getWhitePlaying() {
    return whitePlaying;
}
