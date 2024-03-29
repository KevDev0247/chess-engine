#include "computer.h"
#include <vector>
using namespace std;

bool Computer::baseCheckLevelTwo(Move move) {
    int dstX = move.dstSquareX;
    int dstY = move.dstSquareY;
    vector<vector<char>> boardArray = board->getBoard();
    char piece = boardArray.at(dstY).at(dstX);

    // perform a simulation for detecting check moves
    Board *simulation = new Board(*board);
    simulation->executeMove(move);
    simulation->switchSide();
    vector<Move> simulationMoves = simulation->getMoves();

    vector<Move> validMoves;
    for (auto move: simulationMoves) {
        if (board->checkValidity(move)) 
            validMoves.push_back(move);
    }

    // if it's a capture move, it satisfies level 2
    delete simulation;

    if (board->getWhitePlaying() && islower(piece)) return true;
    if (!board->getWhitePlaying() && isupper(piece)) return true;

    return false;
}

bool Computer::baseCheckLevelThree(Move move) {
    int dstX = move.dstSquareX;
    int dstY = move.dstSquareY;

    // perform a simulation for detecting moves resulted in the piece being captured
    Board *simulation = new Board(*board);
    simulation->executeMove(move);
    simulation->switchSide();
    vector<Move> simulationMoves = simulation->getMoves();

    vector<Move> validMoves;
    for (auto move: simulationMoves) {
        if (board->checkValidity(move)) 
            validMoves.push_back(move);
    }

    delete simulation;
    
    // if a move result in a cgeck or the piece being captured, doesn't satisfy level 3
    for (auto validMove : validMoves) {
        if (validMove.dstSquareX == dstX && validMove.dstSquareY == dstY)
            return false;
        if (board->inChecks()) 
            return false;
    }
    return true;
}
