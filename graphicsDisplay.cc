#include "graphicsDisplay.h"
#include <string>

GraphicsDisplay::GraphicsDisplay(Board *board) : BoardDisplay{board} {
  xw = nullptr;
}



void GraphicsDisplay::notify() {
  if (!xw) {
    xw = new Xwindow(400, 400);
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      int color;
      if (i % 2 == j % 2) {
        color = Xwindow::White;
      } else {
        color = Xwindow::Brown;
      }
      xw->fillRectangle(j * 50, i * 50, 50, 50, color);
      char piece = board->getBoard()[j][i];
      if (piece == 'k' || piece == 'K') {
        if (piece == 'k') {
            xw->fillRectangle(j * 50, i * 50, 50, 50, Xwindow::Red);
        } else {
            xw->fillRectangle(j * 50, i * 50, 50, 50, Xwindow::Blue);
        }
      } else if (piece == 'N' || piece == 'n') {
        if (piece == 'n') {
            xw->fillRectangle(j * 50 + 10, i * 50 + 10, 30, 30, Xwindow::Red);
        } else {
            xw->fillRectangle(j * 50 + 10, i * 50 + 10, 30, 30, Xwindow::Blue);
        }
      } else if (piece == 'p' || piece == 'P') {
        if (piece == 'p') {
            xw->fillRectangle(j * 50 + 20, i * 50 + 20, 10, 10, Xwindow::Red);
        } else {
            xw->fillRectangle(j * 50 + 20, i * 50 + 20, 10, 10, Xwindow::Blue);
        }
      } else if (piece == 'B' || piece == 'b') {
        if (piece == 'b') {
            xw->fillRectangle(j * 50 + 15, i * 50 + 15, 20, 20, Xwindow::Red);
        } else {
            xw->fillRectangle(j * 50 + 15, i * 50 + 15, 20, 20, Xwindow::Blue);
        }
      } else if (piece == 'R' || piece == 'r') {
        if (piece == 'r') {
            xw->fillRectangle(j * 50 + 15, i * 50 + 15, 20, 20, Xwindow::Red);
        } else {
            xw->fillRectangle(j * 50 + 15, i * 50 + 15, 20, 20, Xwindow::Blue);
        }
      } else if (piece == 'Q' || piece == 'q') {
        if (piece == 'q') {
            xw->fillRectangle(j * 50 + 15, i * 50 + 15, 20, 20, Xwindow::Red);
        } else {
            xw->fillRectangle(j * 50 + 15, i * 50 + 15, 20, 20, Xwindow::Blue);
        }
      }
    }
  }
}

GraphicsDisplay::~GraphicsDisplay() {
  delete xw;
}