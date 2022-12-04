#include "levelOne.h"
#include "pieceMoveGen.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Move LevelOne::getMove() {
    vector<Move> moves = board->getMoves();
    
    vector<Move> levelOneMoves;
    for (auto move : moves) {
        if (board->baseCheckValidity(move)) 
            levelOneMoves.push_back(move);
    }

    srand((unsigned int)time(NULL));
    int range = levelOneMoves.size();
    int randomNum = rand() % range;

    cout << " range is " << range << " random " << randomNum << endl;

    return levelOneMoves.at(randomNum);
}
