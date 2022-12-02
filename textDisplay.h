#include "display.h"

class TextDisplay : public Display {
  public:
    TextDisplay(Board *board);
    void notify() override;
};