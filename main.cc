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
#include "graphicsDisplay.h"
using namespace std;

/* read input and facilitate human move */
void humanMove(string origin, string dest, Board* board, Human* human, char promotion) {
    int originX = origin[0] - 'a';
    int originY = origin[1] - '1';
    originY = 7 - originY;
    int destX = dest[0] - 'a';
    int destY = dest[1] - '1';
    destY = 7 - destY;
    char piece = board->getBoard().at(originY).at(originX);

    // create a new move and check its validity
    Move newMove = {
        originX,
        originY,
        destX,
        destY,
        ' ',
        piece,
        MoveType::Normal
    };
    bool success = human->checkValidity(newMove);

    // if human move successful, switch side on board
    // else debugging for now
    if (promotion != ' ') {
        board->executePromote(newMove, promotion);
        board->switchSide();
        board->notifyDisplays();
    } else if ((newMove.piece == 'k' || newMove.piece == 'K') && (abs(originX - destX) >= 2)) {
        board->executeCastle(newMove);
        board->switchSide();
        board->notifyDisplays();
    } else if (success) {
        board->executeMove(newMove);
        board->switchSide();
        board->notifyDisplays();
    } else {
        cout << "bad move" << endl;
        // debugging
        board->notifyDisplays();
    }
}

/* computer generate a move */
void computerMove(Computer *computer, Board *board) {
    vector<Move> moves = board->getMoves();
    vector<Move> levelOneMoves;
    for (auto validMove : moves) {
        if (board->checkValidity(validMove)) 
            levelOneMoves.push_back(validMove);
    }

    if (!levelOneMoves.empty()) {
        Move newMove = computer->getMove();
        cout << "this move is from " << newMove.originSquareY << " " << newMove.originSquareX << "to " 
            << newMove.dstSquareY << " " << newMove.dstSquareY << endl;
        board->executeMove(newMove);
        board->notifyDisplays();
        board->switchSide();        
    }
    /*
    if (levelOneMoves.empty() && !board->inCheckmate() && !board->inChecks()) {
        cout << "tie" << endl;
        board->notifyDisplays();
    }
    */
}

/* initialize a default board */
void initializeBoard(Board *board) {
    for (int i = 0; i < 8; i++) {
        board->setPieceOnBoard(1, i, 'p');
        board->setPieceOnBoard(6, i, 'P');
    }

    board->setPieceOnBoard(0, 0, 'r');
    board->setPieceOnBoard(0, 7, 'r');
    board->setPieceOnBoard(7, 0, 'R');
    board->setPieceOnBoard(7, 7, 'R');

    board->setPieceOnBoard(0, 1, 'n');
    board->setPieceOnBoard(0, 6, 'n');
    board->setPieceOnBoard(7, 1, 'N');
    board->setPieceOnBoard(7, 6, 'N');

    board->setPieceOnBoard(0, 2, 'b');
    board->setPieceOnBoard(0, 5, 'b');
    board->setPieceOnBoard(7, 2, 'B');
    board->setPieceOnBoard(7, 5, 'B');

    board->setPieceOnBoard(0, 3, 'q');
    board->setPieceOnBoard(0, 4, 'k');
    board->setPieceOnBoard(7, 3, 'Q');
    board->setPieceOnBoard(7, 4, 'K');
}

int main() {
    string input;
    string whiteType;
    string blackType;
    string turn = "White";

    Board *board = new Board();
    TextDisplay *textDisplay = new TextDisplay(board);
    GraphicsDisplay *graphicsDisplay = new GraphicsDisplay(board);

    Human *human = new Human(board);
    Computer *whiteComputer = nullptr;
    Computer *blackComputer = nullptr;

    int whiteScore = 0, blackScore = 0;
    int level = 0;
    bool setup = false;

    board->attachDisplay(textDisplay);
    board->attachDisplay(graphicsDisplay);
    
    while (!cin.eof()) {
        getline(cin, input);
        istringstream ss{ input };
        
        if (input.size() == 0) {
            continue;
        } else {
            string command;
            ss >> command;
            if (command == "game") {
                // initial board setup (with or without setup)
                if (!setup) initializeBoard(board);

                // parse level input and reset type to "computer"
                ss >> whiteType >> blackType;
                if (whiteType != "human") {
                    level = whiteType[9] - '0';
                    whiteType = "computer";

                    // instantiate white computer based on the input level
                    if (level == 1) whiteComputer = new LevelOne(board);
                    if (level == 2) whiteComputer = new LevelTwo(board);
                    if (level == 3) whiteComputer = new LevelThree(board);
                }
                if (blackType != "human") {
                    level = whiteType[9] - '0';
                    blackType = "computer";

                    // instantiate black computer based on the input level
                    if (level == 1) blackComputer = new LevelOne(board);
                    if (level == 2) blackComputer = new LevelTwo(board);
                    if (level == 3) blackComputer = new LevelThree(board);
                }
            }
            if (command == "resign") {
                if (board->getWhitePlaying()) {
                    // Can also include this in Game with ostream
                    ++blackScore;
                    cout << "Black wins!" << endl;
                } else {
                    ++whiteScore;
                    cout << "White wins!" << endl;
                }
            }
            if (command == "move") {
                if (board->getWhitePlaying()) {
                    if (whiteType == "human") {
                        // Human input a move and execute it
                        string origin;
                        string dest;
                        ss >> origin >> dest;
                        char promotion;
                        if (ss >> promotion) {
                           humanMove(origin, dest, board, human, promotion);
                        } else {
                           humanMove(origin, dest, board, human, ' ');
                        }
                    } else {
                        // Computer generate a move and execute it
                        computerMove(whiteComputer, board);
                    }
                    turn = "Black";
                } else {
                    if (blackType == "human") {
                        // Human input a move and execute it
                        string origin;
                        string dest;
                        ss >> origin >> dest;
                        char promotion;
                        if (ss >> promotion) {
                           humanMove(origin, dest, board, human, promotion);
                        } else {
                           humanMove(origin, dest, board, human, ' ');
                        }
                    } else {
                        // Computer generate a move and execute it
                        computerMove(blackComputer, board);
                    }
                    turn = "White";
                }
                if (board->inStalemate()) {
                    cout << "Stalemate! It is a draw." << endl;
                    break;
                }
                if (board->insufficientMaterial()) {
                    cout << "Insufficient material! It is a draw." << endl;
                    break;
                }
                if (board->inCheckmate()) {
                    if (board->getWhitePlaying()) {
                        ++blackScore;
                        cout << "Checkmate! Black wins!" << endl;
                    } else {
                        cout << "Checkmate! White wins!" << endl;
                        ++whiteScore;
                    }
                    break;
                }
                if (board->inChecks()) {
                    if (board->getWhitePlaying()) {
                        cout << "White is in check." << endl;
                    } else {
                        cout << "Black is in check." << endl;
                    }
                }
            }
            if (command == "setup") {
                setup = true;
                while (!cin.eof()) {
                    string setupInput, action;
                    getline(cin, setupInput);

                    istringstream ssSetup{ setupInput };
                    ssSetup >> action;

                    // add a piece on board
                    if (action == "+") {
                        string piece, location;
                        ssSetup >> piece >> location;

                        int x = location[0] - 'a';
                        int y = 7 - (location[1] - '1');

                        board->setPieceOnBoard(y, x, piece[0]);
                    }
                    // remove a piece on board
                    if (action == "-") {
                        string location;
                        ssSetup >> location;

                        int x = location[0] - 'a';
                        int y = 7 - (location[1] - '1');
                        board->removePiece(y, x);
                    }
                    // set the color to play next
                    if (action == "=") {
                        string colour;
                        ssSetup >> colour;

                        if (colour == "B") board->setWhitePlaying(false);
                        if (colour == "W") board->setWhitePlaying(true);
                    }
                    if (action == "done") {
                        board->notifyDisplays();
                        break;
                    }
                }              
            }
        }
    }

    cout << "Final Score:" << endl;
    cout << "White: " << whiteScore << endl;
    cout << "Black: " << blackScore << endl;

    delete textDisplay;
    delete graphicsDisplay;
    delete board;
    if (blackComputer) delete blackComputer;
    if (whiteComputer) delete whiteComputer;
    delete human;
    
    return 0;
}
