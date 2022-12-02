#include <iostream>
#include <sstream>
#include "move.h"
#include "board.h"
#include "human.h"
#include "computer.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "textDisplay.h"
using namespace std;

void humanMove(string origin, string dest, Board* board) {
    int originX = origin[1] - 'a';
    int originY = (int)origin[0];
    int destX = dest[1] - 'a';
    int destY = (int)dest[0];
    char piece = board->getBoard().at(originY).at(originX);

    Move newMove = {
        originX,
        originY,
        destX,
        destY,
        ' ',
        piece,
        MoveType::Normal
    };
    bool success = board->baseCheckValidity(newMove);

    // if human move successful, switch side on board
    // else debugging for now
    if (success) {
        board->executeMove(newMove);
        board->switchSide();
    } else {
        cout << "bad move" << endl;
    }
}

void computerMove(Computer *computer, Board *board) {
    Move newMove = computer->getMove();
    board->executeMove(newMove);
    board->switchSide();
}

int main() {
    string input;
    // Can encapsulate all of this information in the Game class for better style
    string whiteType;
    string blackType;
    string turn = "White";
    int whiteScore = 0, blackscore = 0;

    Board *board = new Board();
    TextDisplay *textDisplay = new TextDisplay(board);
    Computer *computer;
    int level;
    
    while (!cin.eof()) {
        getline(cin, input);
        istringstream ss{ input };
        
        if (input.size() == 0) {
            continue;
        } else {
            string command;
            ss >> command;
            if (command == "game") {
                ss >> whiteType >> blackType;
                
                // parse level and reset type to "computer"
                if (whiteType != "human") {
                    level = whiteType[9] - '0';
                    whiteType = "computer";
                }
                if (blackType != "human") {
                    level = whiteType[9] - '0';
                    blackType = "computer";
                }
                // instantiate computer based on the input level
                if (level == 1) computer = new LevelOne(board);
                if (level == 2) computer = new LevelTwo(board);
                if (level == 3) computer = new LevelThree(board);
            }
            if (command == "resign") {
                if (turn == "White") {
                    // Can also include this in Game with ostream
                    ++blackscore;
                    cout << turn << " wins!" << endl;
                } else {
                    ++whiteScore;
                    cout << turn << " wins!" << endl;
                }
            }
            if (command == "move") {
                if (board->getWhitePlaying()) {
                    if (whiteType == "human") {
                        // Human input a move and execute it
                        string origin;
                        string dest;
                        ss >> origin >> dest;
                        humanMove(origin, dest, board);
                    } else {
                        // Computer generate a move and execute it
                        computerMove(computer, board);
                    }
                    turn = "Black";
                } else {
                    if (blackType == "human") {
                        // Human input a move and execute it
                        string origin;
                        string dest;
                        ss >> origin >> dest;
                        humanMove(origin, dest, board);
                    } else {
                        // Computer generate a move and execute it
                        computerMove(computer, board);
                    }
                    turn = "White";
                }
                textDisplay->notify();
            }
            if (command == "setup") {
                while (!cin.eof()) {
                    string setupInput, action;
                    getline(cin, setupInput);

                    istringstream ssSetup{ setupInput };
                    ssSetup >> action;

                    if (action == "+") {
                        string piece, location;
                        ssSetup >> piece >> location;

                        int x = location[1] - 'a';
                        int y = (int)location[0];
                        board->setPieceOnBoard(x, y, piece[0]);
                    }
                    if (action == "-") {
                        string location;
                        ssSetup >> location;

                        int x = location[1] - 'a';
                        int y = (int)location[0];
                        board->removePiece(x, y);
                    }
                    if (action == "=") {
                        string colour;
                        ssSetup >> colour;

                        if (colour == "B") board->setWhitePlaying(false);
                        if (colour == "W") board->setWhitePlaying(true);
                    }
                    if (action == "done") break;
                }              
            }
        }
    }

    return 0;
}
