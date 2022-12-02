#include "board.h"
#include "pieceMoveGen.h"
#include <vector>
using namespace std;

Board::Board() {
    for (int i = 0; i < 7; i++) {
        vector<char> row;
        for (int i = 0; i < 7; i++) {
            row.push_back('-');
        }
        board.push_back(row);
    }
    whitePlaying = true;
}

void Board::setPieceMoveGen(PieceMoveGen *moveGen) {
    this->moveGen = moveGen;
}

// first assume valid input, add checks later
bool Board::setPieceOnBoard(int row, int col, char piece) {
    board.at(row).at(col) = piece;
}

void Board::switchSide() {
    if (getWhitePlaying()) 
        setWhitePlaying(false);
    else 
        setWhitePlaying(true);
}

// first assume valid input, add checks later
void Board::removePiece(int row, int col) {
    board.at(row).at(col) = '-';
}

void Board::setWhitePlaying(bool isWhitePlaying) {
    whitePlaying = isWhitePlaying;
}

bool Board::executeMove(Move move) {
    if (baseCheckValidity(move)) {
        board.at(move.dstSquareY).at(move.dstSquareX) = move.piece;
        board.at(move.originSquareY).at(move.originSquareX) = '-';
        return true;
    }
    return false;
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