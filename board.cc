#include "board.h"
#include "pieceMoveGen.h"
#include "emptyMoveGen.h"
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

    KingMoveGen *kingMoveGen = new KingMoveGen(new EmptyMoveGen(this), this);
    QueenMoveGen *queenMoveGen = new QueenMoveGen(kingMoveGen, this);
    KnightMoveGen *knightMoveGen = new KnightMoveGen(queenMoveGen, this);
    RookMoveGen *rookMoveGen = new RookMoveGen(knightMoveGen, this);
    BishopMoveGen *bishopMoveGen = new BishopMoveGen(rookMoveGen, this);
    PawnMoveGen *pawnMoveGen = new PawnMoveGen(bishopMoveGen, this);

    this->moveGen = pawnMoveGen; 
    this->whitePlaying = true;   
}

Board::Board(const Board &other) : whitePlaying{other.whitePlaying}, canCastleWhite{other.canCastleWhite} {
    Board *newBoard = new Board();
    for (auto row : other.board) {
        vector<char> newRow;
        for (auto col : row) {
            newRow.push_back(col);
        }
        newBoard->getBoard().push_back(newRow);
    }
}

bool Board::setPieceOnBoard(int row, int col, char piece) {
    board.at(row).at(col) = piece;
}

void Board::attachDisplay(BoardDisplay* display) {
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

void Board::setCanCastleWhite(bool isAbleToCastleWhite) {
    canCastleWhite = isAbleToCastleWhite;
}

void Board::executeMove(Move move) {
    board.at(move.dstSquareY).at(move.dstSquareX) = move.piece;
    board.at(move.originSquareY).at(move.originSquareX) = ' ';
}

void Board::executeCastle(Move move) {
    if ((move.piece == 'k') && (move.dstSquareX == 6)) {
        board.at(0).at(6) = 'k';
        board.at(0).at(5) = 'r';
        board.at(0).at(4) = ' ';
        board.at(0).at(7) = ' ';
    } else if (move.piece == 'k') {
        board.at(0).at(2) = 'k';
        board.at(0).at(3) = 'r';
        board.at(0).at(0) = ' ';
        board.at(0).at(1) = ' ';
        board.at(0).at(4) = ' ';
    } else if ((move.piece == 'K') && (move.dstSquareX == 6)) {
        board.at(7).at(6) = 'K';
        board.at(7).at(5) = 'R';
        board.at(7).at(4) = ' ';
        board.at(7).at(7) = ' ';
    } else if (move.piece == 'K') {
        board.at(7).at(2) = 'K';
        board.at(7).at(3) = 'R';
        board.at(7).at(0) = ' ';
        board.at(7).at(1) = ' ';
        board.at(7).at(4) = ' ';
    }
}

std::vector<Move> Board::getMoves() {
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

bool Board::getCanCastleWhite() {
    return canCastleWhite;
}

bool Board::inChecks() {
    vector<Move> generatedMoves = getMoves();
    for (auto move : generatedMoves)
        if (board.at(move.dstSquareY).at(move.dstSquareX) == 'K' || 'k')
            return true;
    return false;
}

bool Board::inCheckmate() {
    if (inChecks()) {
        Board *simulation{this};
        simulation->switchSide();
        vector<Move> generatedMoves = simulation->getMoves();
        if (generatedMoves.size() == 0) return true;
    }
    return false;
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
