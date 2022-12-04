#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "player.h"
#include "boarddisplay.h"
#include "moveGen.h"

class MoveGen;
class PieceMoveGen;
class BoardDisplay;

class Board {
    PieceMoveGen *moveGen;
    std::vector<BoardDisplay*> displays;
    std::vector<std::vector<char>> board;
    bool canCastleWhite;
    bool whitePlaying;

    public:
        Board();
        Board(const Board &other);
        ~Board();

        void displayBoard();
        void attachDisplay(BoardDisplay* display);
        void detachDisplay(BoardDisplay* display);
        void notifyDisplays();

        void setWhitePlaying(bool whitePlaying);
        void setCanCastleWhite(bool canCastleWhite);
        bool setPieceOnBoard(int row, int col, char piece);
        void removePiece(int row, int col);
        void executeMove(Move move);
        void executeCastle(Move move);
        void switchSide();

        std::vector<std::vector<char>> getBoard();
        std::vector<Move> getMoves(bool simulateCheck=true);
        std::vector<Move> legalMoves();
        MoveGen* getMoveGen();
        Move attacks();
        bool inChecks();
        bool inCheckmate();
        bool causeCheck();
        std::string getFEN();
        bool getWhitePlaying();
        bool getCanCastleWhite();

        bool baseCheckValidity(Move move, bool simulateCheck=true);
};

#endif
