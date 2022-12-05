#include "boarddisplay.h"

class TextDisplay : public BoardDisplay {
  public:
    TextDisplay(Board *board);
    void notify() override;
};
