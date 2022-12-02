#include <iostream>
#include <sstream>
#include "move.h"
#include "board.h"
#include "human.h"
#include "computer.h"
using namespace std;

int main() {
    string input;
    // Can encapsulate all of this information in the Game class for better style
    string whiteType;
    string blackType;
    Board *board = new Board();
    string turn = "White";
    int whiteScore = 0, blackscore = 0;
    bool humanVsComputer = false;
    
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
                if (whiteType == "computer" && blackType == "computer") {
                    // separate control logic, doesn't go thru move command
                }
                if (whiteType == "computer" && blackType == "human") {
                    // computer make a move here, logic here
                    humanVsComputer = true;
                }
                if (whiteType == "human" && blackType == "computer") {
                    // human make a move first, which is below
                    humanVsComputer = true;
                }
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
                string origin;
                string dest;
                ss >> origin >> dest;
                
                int originX = origin[1] - 'a';
                int originY = (int)origin[0];
                int destX = dest[1] - 'a';
                int destY = (int)dest[0];
                char piece = board->getBoard().at(originY).at(originX);

                bool success = board->executeMove({
                    originX,
                    originY,
                    destX,
                    destY,
                    ' ',
                    piece,
                    MoveType::Normal
                });
                if (success) {
                    if (board->getWhitePlaying()) 
                        board->setWhitePlaying(false);
                    else 
                        board->setWhitePlaying(true);

                    if (humanVsComputer) {
                        // computer make a move here
                    }
                } else {
                    cout << "bad move" << endl;
                }

                // if (turn == "White") {
                //     if (whiteType == "human") {
                        
                //         // debugging for now
                //     } else {
                //         // getMove from computer level
                //     }
                //     turn = "Black";
                // } else {
                //     if (blackType == "human") {
                //         string start;
                //         string end;
                //         ss >> start >> end;
                //     } else {
                //         // getMove from computer level
                //     }
                //     turn = "White";
                // }
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
