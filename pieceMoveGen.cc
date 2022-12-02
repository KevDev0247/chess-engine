#include "pieceMoveGen.h"
using namespace std;

vector<Move> PieceMoveGen::getMoves() {
    return next->getMoves();
}

PieceMoveGen::~PieceMoveGen() { delete next; }

vector<Move> KnightMoveGen::getMoves() {
  vector<Move> result = next->getMoves();
  auto boardArray = board->getBoard();
  bool white = board->getWhitePlaying();
  vector<Move> newMoves;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (boardArray[i][j] == 'h' || boardArray[i][j] == 'H') {
        newMoves.push_back({
          j,
          i,
          j + 1,
          i + 2,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        newMoves.push_back({
          j,
          i,
          j + 2,
          i + 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        newMoves.push_back({
          j,
          i,
          j - 1,
          i - 2,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        newMoves.push_back({
          j,
          i,
          j - 2,
          i - 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        newMoves.push_back({
          j,
          i,
          j - 1,
          i + 2,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        newMoves.push_back({
          j,
          i,
          j - 2,
          i + 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        newMoves.push_back({
          j,
          i,
          j + 1,
          i - 2,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        newMoves.push_back({
          j,
          i,
          j + 2,
          i - 1,
          ' ',
          boardArray[i][j],
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
          boardArray[i][j],
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j + 1,
          i,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j + 1,
          i - 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j,
          i + 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j,
          i - 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j - 1,
          i - 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j - 1,
          i,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });

        newMoves.push_back({
          j,
          i,
          j - 1,
          i + 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
      }
      
      if (boardArray[i][j] == 'p' || boardArray[i][j] == 'P') {
        newMoves.push_back({
          j,
          i,
          j + 1,
          i,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        newMoves.push_back({
          j,
          i,
          j - 1,
          i,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        newMoves.push_back({
          j,
          i,
          j,
          i + 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        newMoves.push_back({
          j,
          i,
          j,
          i + 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
      }
      if (boardArray[i][j] == 'r' || boardArray[i][j] == 'R') {
        for (int k = 0; k < 8; k++) {
          if (k != j) 
            newMoves.push_back({
              j,
              i,
              k,
              i,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            });          
        }
        for (int k = 0; k < 8; k++) {
          if (k != i)
            newMoves.push_back({
              j,
              i,
              j,
              k,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            });          
        }
      }
      if (boardArray[i][j] == 'b' || boardArray[i][j] == 'B') {
        // int firstQuadrant, secondQuadrant, thirdQuadrant, fourthQuadrant;
        // if (8 - j > i) firstQuadrant = j;
        // else firstQuadrant = 8 - i;
        // if (i > j) secondQuadrant = j;
        // else secondQuadrant = i;
        // if (8 - i > 8 - j) secondQuadrant = 8 - j;
        // else secondQuadrant = 8 - i;
        // if (8 - i > j) secondQuadrant = 8 - i;
        // else secondQuadrant = j;

        int m = j, k = i;
        while (k > 0 && m < 8) {
          if (k != j) 
            newMoves.push_back({
              j,
              i,
              m,
              k,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            }); 
           m++; k--;
        }

        int m = j, k = i;
        while (k > 0 && m > 0) {
          if (k != j) 
            newMoves.push_back({
              j,
              i,
              m,
              k,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            }); 
           m--; k--;
        }

        int m = j, k = i;
        while (k < 8 && m > 0) {
          if (k != j) 
            newMoves.push_back({
              j,
              i,
              m,
              k,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            }); 
           m--; k++;
        }

        int m = j, k = i;
        while (k < 8 && m < 8) {
          if (k != j) 
            newMoves.push_back({
              j,
              i,
              m,
              k,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            }); 
           m++; k++;
        }
      }
      if (boardArray[i][j] == 'q' || boardArray[i][j] == 'Q') {
        // horizontal and vertical moves
        for (int k = 0; k < 8; k++) {
          if (k != j) 
            newMoves.push_back({
              j,
              i,
              k,
              i,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            });          
        }
        for (int k = 0; k < 8; k++) {
          if (k != i)
            newMoves.push_back({
              j,
              i,
              j,
              k,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            });          
        }

        // diagonal moves
        int m = j, k = i;
        while (k > 0 && m < 8) {
          if (k != j) 
            newMoves.push_back({
              j,
              i,
              m,
              k,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            }); 
           m++; k--;
        }

        int m = j, k = i;
        while (k > 0 && m > 0) {
          if (k != j) 
            newMoves.push_back({
              j,
              i,
              m,
              k,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            }); 
           m--; k--;
        }

        int m = j, k = i;
        while (k < 8 && m > 0) {
          if (k != j) 
            newMoves.push_back({
              j,
              i,
              m,
              k,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            }); 
           m--; k++;
        }

        int m = j, k = i;
        while (k < 8 && m < 8) {
          if (k != j) 
            newMoves.push_back({
              j,
              i,
              m,
              k,
              ' ',
              boardArray[i][j],
              MoveType::Normal
            }); 
           m++; k++;
        }
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