#include "display.h"

class TextDisplay : public Display {
  TextDisplay(Board *board) : board{board} {};
  void notify() override;
};