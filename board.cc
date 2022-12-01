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

bool Board::baseCheckValidity(Move move) {
    int dstX = move.dstSquareX;
    int dstY = move.dstSquareY;
    int originX = move.originSquareX;
    int originY = move.originSquareY;

    if (!(dstX > 0 && dstX < board.front().size() && dstY > 0 && dstY < board.size())) 
        return false;

    char originPiece = board.at(originY).at(originX);
    char dstPiece = board.at(dstY).at(dstX);
    int vertical = abs(originY - dstY);
    int horizontal = abs(originX - dstX);

    if (whitePlaying && isupper(dstPiece)) return false;
    if (whitePlaying && islower(originPiece)) return false;
    if (!whitePlaying && islower(dstPiece)) return false;
    if (!whitePlaying && isupper(originPiece)) return false;

    if ((originPiece == 'P' || 'p') && !((horizontal == 1 && vertical == 0) || (horizontal == 0 && vertical == 1))) return false;
    if ((originPiece == 'K' || 'k') && !(horizontal == 1 || vertical == 1)) return false;
    if ((originPiece == 'Q' || 'q') && !(horizontal == vertical || horizontal == 0 || vertical == 0)) return false;
    if ((originPiece == 'R' || 'r') && !(horizontal == 0 || vertical == 0)) return false;
    if ((originPiece == 'B' || 'b') && !(horizontal == vertical)) return false;
    if ((originPiece == 'H' || 'h') && !((horizontal == 2 && vertical == 1) || (horizontal == 1 && vertical == 2))) return false;

    return true;
}