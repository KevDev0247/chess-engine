#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string input;

    while (!cin.eof()) {
        getline(cin, input);
        istringstream ss{ input };
        
        if (input.size() == 0) {
            continue;
        } else {
            string command;
            ss >> command;
            if (command == "game") {
                string white;
                string black;

                ss >> white >> black;
                if (white == "human") {
                    
                } else {

                }

                if (black == "human") {

                } else {

                }
            }
            if (command == "resign") {
                // need a field in player to determine turn and decide
            }
            if (command == "move") {
                string start;
                string end;

                ss >> start >> end;
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
