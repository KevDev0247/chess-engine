#include "display.h"

class GraphicsDisplay : public Display {
  GraphicsDisplay(Board *board) : board{board} {};
  void notify() override;
};