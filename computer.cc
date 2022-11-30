#include "computer.h"
using namespace std;

bool Computer::baseCheckLevelTwo(Board boardClass, Move move) {
    int dstX = move.getDstSquareX();
    int dstY = move.getDstSquareY();
    vector<vector<char>> board = boardClass.getBoard();
    char piece = board.at(dstY).at(dstX);

    if (boardClass.getWhitePlaying() && islower(piece)) return true;
    if (!boardClass.getWhitePlaying() && isupper(piece)) return true;
    return false;
}

bool Computer::baseCheckLevelThree(Board boardClass, Move move) {
    // add checks and return false
    return true;
}