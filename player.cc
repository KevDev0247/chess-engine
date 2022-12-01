#include "player.h"
#include <vector>
using namespace std;

bool Player::baseCheckValidity(Move move) {
    int dstX = move.dstSquareX;
    int dstY = move.dstSquareY;
    int originX = move.originSquareX;
    int originY = move.originSquareY;
    bool white = board->getWhitePlaying();
    vector<vector<char>> boardArray = board->getBoard();

    if (!(dstX > 0 && dstX < boardArray.front().size() && dstY > 0 && dstY < boardArray.size())) 
        return false;

    char originPiece = boardArray.at(originY).at(originX);
    char dstPiece = boardArray.at(dstY).at(dstX);
    int vertical = abs(originY - dstY);
    int horizontal = abs(originX - dstX);

    if (white && isupper(dstPiece)) return false;
    if (white && islower(originPiece)) return false;
    if (!white && islower(dstPiece)) return false;
    if (!white && isupper(originPiece)) return false;

    if ((originPiece == 'P' || 'p') && !((horizontal == 1 && vertical == 0) || (horizontal == 0 && vertical == 1))) return false;
    if ((originPiece == 'K' || 'k') && !(horizontal == 1 || vertical == 1)) return false;
    if ((originPiece == 'Q' || 'q') && !(horizontal == vertical || horizontal == 0 || vertical == 0)) return false;
    if ((originPiece == 'R' || 'r') && !(horizontal == 0 || vertical == 0)) return false;
    if ((originPiece == 'B' || 'b') && !(horizontal == vertical)) return false;
    if ((originPiece == 'H' || 'h') && !((horizontal == 2 && vertical == 1) || (horizontal == 1 && vertical == 2))) return false;

    return true;
}