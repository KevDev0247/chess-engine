#include "pieceMoveGen.h"
using namespace std;

vector<Move> PieceMoveGen::getMoves() {
    return next->getMoves();
}

PieceMoveGen::~PieceMoveGen() { delete next; }

vector<Move> KingMoveGen::getMoves() {
  vector<Move> result = next->getMoves();
  auto boardArray = board->getBoard();
  bool white = board->getWhitePlaying();
  vector<Move> newMoves;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (boardArray[i][j] == 'k' || boardArray[i][j] == 'K') {
        newMoves.push_back({
          j,
          i,
          j + 1,
          i + 1,
          ' ',
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j + 1,
          i,
          ' ',
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j + 1,
          i - 1,
          ' ',
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j,
          i + 1,
          ' ',
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j,
          i - 1,
          ' ',
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j - 1,
          i - 1,
          ' ',
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j - 1,
          i,
          ' ',
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j - 1,
          i + 1,
          ' ',
          MoveType::Normal
        });
      }
    }
  }

  for (auto &i : newMoves) {
    if (board->baseCheckValidity(i)) {
      result.push_back(i);
    }
  }
  return result;
}