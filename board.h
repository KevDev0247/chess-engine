#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "player.h"
#include "display.h"

class PieceMoveGen;

class Board {
    std::vector<std::vector<char>> board;
    bool canCastleWhite;
    bool whitePlaying;
    std::vector<Display*> displays;
    PieceMoveGen *moveGen;

    public:
        Board();
        ~Board();

        void displayBoard();
        void attachDisplay(Display* display);
        void detachDisplay(Display* display);

        void setPieceMoveGen(PieceMoveGen *moveGen);
        void setWhitePlaying(bool whitePlaying);
        bool setPieceOnBoard(int row, int col, char piece);
        void removePiece(int row, int col);
        void executeMove(Move move);
        void switchSide();

        std::vector<std::vector<char>> getBoard();
        std::vector<Move> getMoves();
        std::vector<Move> legalMoves();
        Move attacks();
        bool inChecks();
        bool causeCheck();
        std::string getFEN();
        bool getWhitePlaying();

        bool baseCheckValidity(Move move);
};

#endif
