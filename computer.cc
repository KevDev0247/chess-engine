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

    // if it's a check move, it satisfies level 2
    for (auto simulationMove : simulationMoves) {
        char piece = board->getBoard().at(simulationMove.dstSquareY).at(simulationMove.dstSquareX);
        if (piece == 'K' || piece == 'k')
            return true;
    }

    // if it's a capture move, it satisfies level 2
    if (board->getWhitePlaying() && islower(piece)) return true;
    if (!board->getWhitePlaying() && isupper(piece)) return true;

    delete simulation;

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

    // if a move result in a cgeck or the piece being captured, doesn't satisfy level 3
    for (auto simulationMove : simulationMoves) {
        if (simulationMove.dstSquareX == dstX && simulationMove.dstSquareY == dstY)
            return false;
        if (board->inChecks()) 
            return false;
    }
        
    delete simulation;
    
    return true;
}
