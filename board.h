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
    // need moveGen
    public:
        Board();

        // need type for method
        void setPieceMoveGen(PieceMoveGen *moveGen);
        std::vector<Move> getMoves();
        Move attacks();
        bool inChecks();
        bool causeCheck();
        std::vector<Move> legalMoves();
        void displayBoard();
        std::string getFEN();
        void attachDisplay(Display* display);
        void detachDisplay(Display* display);
        bool baseCheckValidity(Move move);
        std::vector<std::vector<char>> getBoard();
        bool getWhitePlaying();
};

#endif
