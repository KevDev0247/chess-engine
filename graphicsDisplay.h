#include "boarddisplay.h"
#include "window.h"

class GraphicsDisplay : public BoardDisplay {
  Xwindow *xw;
public:
  GraphicsDisplay(Board *board);
  void notify() override;
  ~GraphicsDisplay();
};