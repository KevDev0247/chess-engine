#include "player.h"
#include <vector>
using namespace std;

bool Player::baseCheckValidity(Move move) {
    int dstX = move.getDstSquareX();
    int dstY = move.getDstSquareY();
    int originX = move.getOriginSquareX();
    int originY = move.getOriginSquareY();
    bool white = board->getWhitePlaying();
    vector<vector<char>> boardArray = board->getBoard();

    if (!(dstX > 0 && dstX < boardArray.front().size() && dstY > 0 && dstY < boardArray.size())) 
        return false;

    char piece = boardArray.at(dstY).at(dstX);
    int vertical = abs(originY - dstY);
    int horizontal = abs(originX - dstX);

    if (white && isupper(piece)) return false;
    if (!white && islower(piece)) return false;

    if ((piece == 'P' || 'p') && !((horizontal == 1 && vertical == 0) || (horizontal == 0 && vertical == 1))) return false;
    if ((piece == 'K' || 'k') && !(horizontal == 1 || vertical == 1)) return false;
    if ((piece == 'Q' || 'q') && !(horizontal == vertical || horizontal == 0 || vertical == 0)) return false;
    if ((piece == 'R' || 'r') && !(horizontal == 0 || vertical == 0)) return false;
    if ((piece == 'B' || 'b') && !(horizontal == vertical)) return false;
    if ((piece == 'H' || 'h') && !((horizontal == 2 && vertical == 1) || (horizontal == 1 && vertical == 2))) return false;

    return true;
}