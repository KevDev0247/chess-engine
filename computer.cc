#include "computer.h"
#include <vector>
using namespace std;

bool Computer::baseCheckLevelTwo(Move move) {
    int dstX = move.dstSquareX;
    int dstY = move.dstSquareY;
    vector<vector<char>> boardArray = board->getBoard();
    char piece = boardArray.at(dstY).at(dstX);

    if (board->getWhitePlaying() && islower(piece)) return true;
    if (!board->getWhitePlaying() && isupper(piece)) return true;
    return false;
}

bool Computer::baseCheckLevelThree(Move move) {
    int dstX = move.dstSquareX;
    int dstY = move.dstSquareY;

    Board *simulation = new Board(*board);
    simulation->executeMove(move);
    simulation->switchSide();
    vector<Move> generatedMoves = simulation->getMoves();

    for (auto generatedMove : generatedMoves) 
        if (generatedMove.dstSquareX == dstX && generatedMove.dstSquareY == dstY)
            return false;
    
    return true;
}
