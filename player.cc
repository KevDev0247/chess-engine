#include "player.h"
#include <vector>
using namespace std;

Player::Player() {}

bool Player::baseCheckValidity(Board boardClass, Move move) {
    int dstX = move.getDstSquareX();
    int dstY = move.getDstSquareY();
    int originX = move.getOriginSquareX();
    int originY = move.getOriginSquareY();
    vector<vector<char>> board = boardClass.getBoard();

    if (!(dstX > 0 && dstX < board.front().size() && dstY > 0 && dstY < board.size())) 
        return false;

    char piece = board.at(dstY).at(dstX);
    int vertical = abs(originY - dstY);
    int horizontal = abs(originX - dstX);

    if (piece == 'P' && !((horizontal == 1 && vertical == 0) | (horizontal == 0 && vertical == 1))) return false;
    if (piece == 'K' && !(horizontal == 1 | vertical == 1)) return false;
    if (piece == 'Q' && !(horizontal == vertical | horizontal == 0 | vertical == 0)) return false;
    if (piece == 'R' && !(horizontal == 0 | vertical == 0)) return false;
    if (piece == 'B' && !(horizontal == vertical)) return false;
    if (piece == 'H' && !((horizontal == 2 && vertical == 1) | (horizontal == 1 && vertical == 2))) return false;

    return true;
}