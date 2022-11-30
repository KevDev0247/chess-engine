#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "player.h"
#include "display.h"

class Board {
    char **board;
    bool canCastleWhite;
    std::vector<Display*> displays;
    // need moveGen
    public:
        Board();

        // need type for method
        Move attacks();
        bool inChecks();
        bool causeCheck();
        std::vector<Move> legalMoves();
        void displayBoard();
        std::string getFEN();
        void attachDisplay(Display* display);
        void detachDisplay(Display* display);
};

#endif
