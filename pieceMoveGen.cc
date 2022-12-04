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
      if (boardArray[i][j] == 'n' || boardArray[i][j] == 'N') {
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
        if (i == 1 && boardArray[2][j] == ' ' && boardArray[3][j] == ' ') {
          newMoves.push_back({
            j,
            i,
            j,
            3,
            ' ',
            boardArray[i][j],
            MoveType::Normal
          });
        }
        if (i == 7) continue;
        if (i < 7 && boardArray[i + 1][j] == ' ') {
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
        if (j < 7 && isupper(boardArray[i + 1][j + 1])) {
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
        if (j > 0 && isupper(boardArray[i + 1][j - 1])) {
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
        if (i == 6 && boardArray[5][j] == ' ' && boardArray[4][j] == ' ') {
          newMoves.push_back({
            j,
            i,
            j,
            4,
            ' ',
            boardArray[i][j],
            MoveType::Normal
          });
        }
        
        if (i == 0) continue;
        if (boardArray[i - 1][j] == ' ') {
          newMoves.push_back({
            j,
            i,
            j,
            i - 1,
            ' ',
            boardArray[i][j],
            MoveType::Normal
          });
        }
        if (j < 7 && islower(boardArray[i - 1][j + 1])) {
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
        if (j > 0 && islower(boardArray[i - 1][j - 1])) {
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
  vector<Move> result;
  if (next) {
    result = next->getMoves();
  }
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

bool addLinearMove(
  vector<vector<char>> &boardArray,
  int y,
  int x,
  int i,
  int j,
  bool whitePiece,
  vector<Move> &result
) {
  if (whitePiece && isupper(boardArray[i][j])) {
    return false;
  }

  if (!whitePiece && islower(boardArray[i][j])) {
    return false;
  }

  result.push_back({
    x,
    y,
    j,
    i,
    ' ',
    boardArray[y][x],
    MoveType::Normal
  });

  if (whitePiece && islower(boardArray[i][j])) {
    return false;
  }
  if (!whitePiece && isupper(boardArray[i][j])) {
    return false;
  }

  return true;
}


void genRookMoves(
  vector<vector<char>> &boardArray,
  int y,
  int x,
  vector<Move> &result
) {

  bool whitePiece = isupper(boardArray[y][x]);

  // up
  for (int i = y - 1; i >= 0; i--) {
    if (!addLinearMove(boardArray, y, x, i, x, whitePiece, result)) break;
  }

  // down
  for (int i = y + 1; i < 8; i++) {
    if (!addLinearMove(boardArray, y, x, i, x, whitePiece, result)) break;

  }
  // left
  for (int j = x - 1; j >= 0; j--) {
    if (!addLinearMove(boardArray, y, x, y, j, whitePiece, result)) break;
  }

  // right
  for (int j = x + 1; j < 8; j++) {
    if (!addLinearMove(boardArray, y, x, y, j, whitePiece, result)) break;
  }
}



void genBishopMoves(
  vector<vector<char>> &boardArray,
  int y,
  int x,
  vector<Move> &result
) {

  bool whitePiece = isupper(boardArray[y][x]);

  // northwest
  for (int i = y - 1, j = x - 1; i >= 0 && j >= 0; i--, j--) {
    if (!addLinearMove(boardArray, y, x, i, j, whitePiece, result)) break;
  }

  // northeast
  for (int i = y - 1, j = x + 1; i >= 0 && j < 8; i--, j++) {
    if (!addLinearMove(boardArray, y, x, i, j, whitePiece, result)) break;
  }

  // southwest
  for (int i = y + 1, j = x - 1; i < 8 && j >= 0; i++, j--) {
    if (!addLinearMove(boardArray, y, x, i, j, whitePiece, result)) break;
  }

  // southeast
  for (int i = y + 1, j = x + 1; i < 8 && j < 8; i++, j++) {
    if (!addLinearMove(boardArray, y, x, i, j, whitePiece, result)) break;
  }
}
