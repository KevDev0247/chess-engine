#include "display.h"

class TextDisplay : public Display {
  TextDisplay(Board *board) : Display{board} {};
  void notify() override;
};