#include "display.h"

class GraphicsDisplay : public Display {
  GraphicsDisplay(Board *board) : Display{board} {};
  void notify() override;
};