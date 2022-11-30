#include "board.h"

Board::Board() {}

std::vector<std::vector<char>> Board::getBoard() {
    return board;
}

bool Board::getWhitePlaying() {
    return whitePlaying;
}
