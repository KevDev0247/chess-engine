#include "display.h"

class TextDisplay : public Display {
  public:
    TextDisplay(Board *board) : Display{board} {};
    void notify() override;
};