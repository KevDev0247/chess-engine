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
      xw->drawString(j * 50, i * 50, std::string(1, board->getBoard()[j][i]));
    }
  }
}

GraphicsDisplay::~GraphicsDisplay() {
  delete xw;
}