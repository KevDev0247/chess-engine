#include "board.h"
#include "pieceMoveGen.h"
#include <vector>
#include <iostream>
using namespace std;

Board::Board() {
    for (int i = 0; i < 8; i++) {
        vector<char> row;
        for (int i = 0; i < 8; i++) {
            row.push_back(' ');
        }
        board.push_back(row);
    }
}

void Board::setPieceMoveGen(PieceMoveGen *moveGen) {
    this->moveGen = moveGen;
}

bool Board::setPieceOnBoard(int row, int col, char piece) {
    board.at(row).at(col) = piece;
}

void Board::attachDisplay(Display* display) {
    displays.push_back(display);
}

void Board::notifyDisplays() {
  for (auto display : displays) display->notify();
}

void Board::switchSide() {
    if (getWhitePlaying()) 
        setWhitePlaying(false);
    else 
        setWhitePlaying(true);
}

// first assume valid input, add checks later
void Board::removePiece(int row, int col) {
    board.at(row).at(col) = ' ';
}

void Board::setWhitePlaying(bool isWhitePlaying) {
    whitePlaying = isWhitePlaying;
}

void Board::executeMove(Move move) {
    board.at(move.dstSquareY).at(move.dstSquareX) = move.piece;
    board.at(move.originSquareY).at(move.originSquareX) = ' ';
}

std::vector<Move> Board::getMoves() {
    if (moveGen == nullptr) cout << "null movegen" << endl;
    return moveGen->getMoves();
}

std::vector<std::vector<char>> Board::getBoard() {
    return board;
}

MoveGen* Board::getMoveGen() {
    return moveGen;
}

bool Board::getWhitePlaying() {
    return whitePlaying;
}

bool Board::baseCheckValidity(Move move) {
    int dstX = move.dstSquareX;
    int dstY = move.dstSquareY;
    int originX = move.originSquareX;
    int originY = move.originSquareY;

    if (!(dstX >= 0 && dstX < 8 && dstY >= 0 && dstY < 8)) 
        return false;

    char originPiece = board.at(originY).at(originX);
    char dstPiece = board.at(dstY).at(dstX);
    int vertical = abs(originY - dstY);
    int horizontal = abs(originX - dstX);
    // cout << originPiece << ' ' << dstPiece << endl;

    if (whitePlaying && isupper(dstPiece)) return false;
    if (whitePlaying && islower(originPiece)) return false;
    if (!whitePlaying && islower(dstPiece)) return false;
    if (!whitePlaying && isupper(originPiece)) return false;
    // cout << vertical << ' ' << horizontal << endl;

    if ((originPiece == 'P' || originPiece == 'p') && !((horizontal == 0 && vertical == 2) || (horizontal == 0 && vertical == 1)
                                                        || (horizontal == 1 && vertical == 1))) return false;
    if ((originPiece == 'K' || originPiece == 'k') && !(horizontal == 1 || vertical == 1 ||
                                                        (horizontal == 2 && vertical == 0) || (horizontal == 3 && vertical == 0))) return false;
    if ((originPiece == 'Q' || originPiece == 'q') && !(horizontal == vertical || horizontal == 0 || vertical == 0)) return false;
    if ((originPiece == 'R' || originPiece == 'r') && !(horizontal == 0 || vertical == 0)) return false;
    if ((originPiece == 'B' || originPiece == 'b') && !(horizontal == vertical)) return false;
    if ((originPiece == 'N' || originPiece == 'n') && !((horizontal == 2 && vertical == 1) || (horizontal == 1 && vertical == 2))) return false;

    return true;
}
