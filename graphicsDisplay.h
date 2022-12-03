#include "display.h"
#include "window.h"

class GraphicsDisplay : public Display {
  XWindow *xw;
public:
  GraphicsDisplay(Board *board);
  void notify() override;
  ~GraphicsDisplay();
};