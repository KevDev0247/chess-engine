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


vector<Move> RookMoveGen::getMoves() {
  vector<Move> result = next->getMoves();
  auto boardArray = board->getBoard();
  bool white = board->getWhitePlaying();
  vector<Move> newMoves;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((white && boardArray[i][j] == 'R') ||
        (!white && boardArray[i][j] == 'r')) {
        genRookMoves(boardArray, i, j, newMoves);
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


vector<Move> BishopMoveGen::getMoves() {
  vector<Move> result = next->getMoves();
  auto boardArray = board->getBoard();
  bool white = board->getWhitePlaying();
  vector<Move> newMoves;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((white && boardArray[i][j] == 'B') ||
        (!white && boardArray[i][j] == 'b')) {
        genBishopMoves(boardArray, i, j, newMoves);
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

vector<Move> QueenMoveGen::getMoves() {
  vector<Move> result = next->getMoves();
  auto boardArray = board->getBoard();
  bool white = board->getWhitePlaying();
  vector<Move> newMoves;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((white && boardArray[i][j] == 'Q') ||
        (!white && boardArray[i][j] == 'q')) {
        genRookMoves(boardArray, i, j, newMoves);
        genBishopMoves(boardArray, i, j, newMoves);
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

vector<Move> PawnMoveGen::getMoves() {
  vector<Move> result = next->getMoves();
  auto boardArray = board->getBoard();
  bool white = board->getWhitePlaying();
  vector<Move> newMoves;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (boardArray[i][j] == 'p') {
        if (boardArray[i + 1][j] == ' ');
        newMoves.push_back({
          j,
          i,
          j,
          i + 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        if (isupper(boardArray[i + 1][j + 1])) {
          newMoves.push_back({
            j,
            i,
            j + 1,
            i + 1,
            ' ',
            boardArray[i][j],
            MoveType::Normal
          });
        }
        if (isupper(boardArray[i + 1][j - 1])) {
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
      } else if (boardArray[i][j] == 'P') {
        if (boardArray[i - 1][j] == ' ');
        newMoves.push_back({
          j,
          i,
          j,
          i - 1,
          ' ',
          boardArray[i][j],
          MoveType::Normal
        });
        if (islower(boardArray[i - 1][j + 1])) {
          newMoves.push_back({
            j,
            i,
            j + 1,
            i + 1,
            ' ',
            boardArray[i][j],
            MoveType::Normal
          });
        }
        if (islower(boardArray[i - 1][j - 1])) {
          newMoves.push_back({
            j,
            i,
            j - 1,
            i - 1,
            ' ',
            boardArray[i][j],
            MoveType::Normal
          });
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
    }
  }

  for (auto &i : newMoves) {
    if (board->baseCheckValidity(i)) {
      result.push_back(i);
    }
  }
  return result;
}


void genRookMoves(
  vector<vector<char>> &boardArray,
  int y,
  int x,
  vector<Move> &result
) {

  bool whitePiece = isupper(boardArray[y][x]);

  // up
  for (int i = y; i >= 0; i--) {
    if (whitePiece && isupper(boardArray[i][x])) {
      break;
    }

    if (!whitePiece && islower(boardArray[i][x])) {
      break;
    }

    result.push_back({
      y,
      x,
      i,
      x,
      ' ',
      boardArray[y][x],
      MoveType::Normal
    });

    if (whitePiece && islower(boardArray[i][x])) {
      break;
    }
    if (!whitePiece && isupper(boardArray[i][x])) {
      break;
    }
  }

  // down
  for (int i = y; i < 8; i++) {
    if (whitePiece && isupper(boardArray[i][x])) {
      break;
    }

    if (!whitePiece && islower(boardArray[i][x])) {
      break;
    }

    result.push_back({
      y,
      x,
      i,
      x,
      ' ',
      boardArray[y][x],
      MoveType::Normal
    });

    if (whitePiece && islower(boardArray[i][x])) {
      break;
    }
    if (!whitePiece && isupper(boardArray[i][x])) {
      break;
    }

  }
  // left
  for (int j = x; j >= 0; j--) {
    if (whitePiece && isupper(boardArray[y][j])) {
      break;
    }

    if (!whitePiece && islower(boardArray[y][j])) {
      break;
    }

    result.push_back({
      y,
      x,
      y,
      j,
      ' ',
      boardArray[y][j],
      MoveType::Normal
    });

    if (whitePiece && islower(boardArray[y][j])) {
      break;
    }
    if (!whitePiece && isupper(boardArray[y][j])) {
      break;
    }
  }

  // right
  for (int j = x; j < 8; j++) {
    if (whitePiece && isupper(boardArray[y][j])) {
      break;
    }

    if (!whitePiece && islower(boardArray[y][j])) {
      break;
    }

    result.push_back({
      y,
      x,
      y,
      j,
      ' ',
      boardArray[y][j],
      MoveType::Normal
    });

    if (whitePiece && islower(boardArray[y][j])) {
      break;
    }
    if (!whitePiece && isupper(boardArray[y][j])) {
      break;
    }
  }
}
