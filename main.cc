#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string input;
    // Can encapsulate all of this information in the Game class for better style
    string whiteType;
    string blackType;
    string turn = "White";
    int whiteScore = 0, blackscore = 0;
    
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
                if (turn == "White") {
                    if (whiteType == "human") {
                        string start;
                        string end;
                        ss >> start >> end;
                    } else {
                        // getMove from computer level
                    }
                    turn = "Black";
                } else {
                    if (blackType == "human") {
                        string start;
                        string end;
                        ss >> start >> end;
                    } else {
                        // getMove from computer level
                    }
                    turn = "White";
                }
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

                    }
                    if (action == "-") {
                        string location;
                        ssSetup >> location;
                        
                    }
                    if (action == "=") {
                        string colour;
                        ssSetup >> colour;
                        if (colour == "B") {

                        }
                        if (colour == "W") {

                        }
                    }   
                    if (action == "done") break;
                }              
            }
        }
    }

    return 0;
}
