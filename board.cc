#include "board.h"
#include "pieceMoveGen.h"
#include "emptyMoveGen.h"
#include <vector>
#include <iostream>
using namespace std;

Board::Board() : whitePlaying{true}, canCastleWhite{false}, whiteInCheck{false}, blackInCheck{false} {
    // initialize an empty board
    for (int i = 0; i < 8; i++) {
        vector<char> row;
        for (int i = 0; i < 8; i++) {
            row.push_back(' ');
        }
        board.push_back(row);
    }

    // Utilize decorator pattern on move generators
    KingMoveGen *kingMoveGen = new KingMoveGen(new EmptyMoveGen(this), this);
    QueenMoveGen *queenMoveGen = new QueenMoveGen(kingMoveGen, this);
    KnightMoveGen *knightMoveGen = new KnightMoveGen(queenMoveGen, this);
    RookMoveGen *rookMoveGen = new RookMoveGen(knightMoveGen, this);
    BishopMoveGen *bishopMoveGen = new BishopMoveGen(rookMoveGen, this);
    PawnMoveGen *pawnMoveGen = new PawnMoveGen(bishopMoveGen, this);

    this->moveGen = pawnMoveGen; 
    // this->whitePlaying = true;   
}

Board::Board(const Board &other) : 
    whitePlaying{other.whitePlaying}, canCastleWhite{other.canCastleWhite}, 
    whiteInCheck{other.whiteInCheck}, blackInCheck{other.blackInCheck} {
    // Perform deep copy of the board
    for (auto row : other.board) {
        vector<char> newRow;
        for (auto col : row) {
            newRow.push_back(col);
        }
        board.push_back(newRow);
    }

    // Utilize decorator pattern on move generators
    KingMoveGen *kingMoveGen = new KingMoveGen(new EmptyMoveGen(this), this);
    QueenMoveGen *queenMoveGen = new QueenMoveGen(kingMoveGen, this);
    KnightMoveGen *knightMoveGen = new KnightMoveGen(queenMoveGen, this);
    RookMoveGen *rookMoveGen = new RookMoveGen(knightMoveGen, this);
    BishopMoveGen *bishopMoveGen = new BishopMoveGen(rookMoveGen, this);
    PawnMoveGen *pawnMoveGen = new PawnMoveGen(bishopMoveGen, this);

    this->moveGen = pawnMoveGen;
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
    // Start a simulation by switching sides
    Board *simulation = new Board(*this);
    simulation->switchSide();

    // if the other side has a move that can capture the king, it is in check
    vector<Move> generatedMoves = simulation->getMoves();
    for (auto move : generatedMoves) {
        char piece = board.at(move.dstSquareY).at(move.dstSquareX);
        if (piece == 'K') {
            whiteInCheck = true;
            delete simulation;
            return true;
        }
        if (piece == 'k') {
            blackInCheck = true;
            delete simulation;
            return true;
        }
    }
    delete simulation;
    return false;
}

bool Board::inCheckmate() {
    if (inChecks()) {
        int kingMoves = 0;
        // vector<Move> generatedMoves = getMoves();
        
        vector<Move> validMoves;
        vector<Move> boardMoves = getMoves();
        for (auto boardMove: boardMoves) {
            if (checkValidity(boardMove)) 
                validMoves.push_back(boardMove);
        }
        for (auto move : validMoves) {
            char piece = board.at(move.originSquareY).at(move.originSquareX);
            if (piece == 'K' || piece == 'k') 
                kingMoves++;
        }

        cout << "king moves " << kingMoves << endl;
        // if king has no more valid moves when in check, it's a checkmate
        if (kingMoves == 0) return true;
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

    // check if moves for the wrong side or capturing piece from the same side
    if (whitePlaying && isupper(dstPiece)) return false;
    if (whitePlaying && islower(originPiece)) return false;
    if (!whitePlaying && islower(dstPiece)) return false;
    if (!whitePlaying && isupper(originPiece)) return false;

    // check if pieces are moving according to rules
    if ((originPiece == 'P' || originPiece == 'p') && !((horizontal == 0 && vertical == 2) || (horizontal == 0 && vertical == 1)
                                                        || (horizontal == 1 && vertical == 1))) return false;
    if ((originPiece == 'K' || originPiece == 'k') && !(horizontal == 1 || vertical == 1 ||
                                                        (horizontal == 2 && vertical == 0) || (horizontal == 3 && vertical == 0))) return false;
    if ((originPiece == 'Q' || originPiece == 'q') && !(horizontal == vertical || horizontal == 0 || vertical == 0)) return false;
    if ((originPiece == 'R' || originPiece == 'r') && !(horizontal == 0 || vertical == 0)) return false;
    if ((originPiece == 'B' || originPiece == 'b') && !(horizontal == vertical)) return false;
    if ((originPiece == 'N' || originPiece == 'n') && !((horizontal == 2 && vertical == 1) || (horizontal == 1 && vertical == 2))) return false;

    // Check if a king move places the king under attack

    return true;
}

bool Board::checkValidity(Move move) {
    // Check if a king move places the king under attack
    char originPiece = board.at(move.originSquareY).at(move.originSquareX);
    if (originPiece == 'K' || originPiece == 'k') {
        Board *simulation = new Board(*this);
        simulation->executeMove(move);
        if (simulation->inChecks()) {
            delete simulation;
            return false;
        }
        delete simulation;
    }

    // this is detecting the wrong piece shud be next next round
    if (whitePlaying && whiteInCheck && originPiece != 'K') return false;
    if (!whitePlaying && blackInCheck && originPiece != 'k') return false;

    if (originPiece == 'Q' || originPiece == 'q') {
        // check pieces in the middle
    }
    if (originPiece == 'R' || originPiece == 'r') {
        // check pieces in the middle
    }
    if (originPiece == 'B' || originPiece == 'b') {
        // check pieces in the middle
    }

    return true;
}
