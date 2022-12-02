#include <iostream>
#include "textDisplay.h"

using namespace std;

TextDisplay::TextDisplay(Board *board) : Display{board} {}

void TextDisplay::notify() {
  std::vector<std::vector<char>> pieces = board->getBoard();
  for (int i = 0; i < 8; i++) {
    cout << i + 1 << ' ';
    for (int j = 0; j < 8; j++) {
      if (pieces[i][j] != ' ') {
        cout << pieces[i][j];
      } else {
        if (i % 2 == j % 2) {
          cout << '_';
        } else {
          cout << ' ';
        }
      }
    }
    cout << '\n';
  }
  cout << "  abcdefgh" << endl;
}