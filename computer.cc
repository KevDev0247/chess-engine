#include "computer.h"
using namespace std;

bool Computer::baseCheckLevelTwo(Move move) {
    int dstX = move.getDstSquareX();
    int dstY = move.getDstSquareY();
    vector<vector<char>> boardArray = board->getBoard();
    char piece = boardArray.at(dstY).at(dstX);

    if (board->getWhitePlaying() && islower(piece)) return true;
    if (!board->getWhitePlaying() && isupper(piece)) return true;
    return false;
}

bool Computer::baseCheckLevelThree(Move move) {
    // add checks and return false
    return true;
}