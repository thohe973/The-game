#include "arrow.h"

Arrow::Arrow()
  : Sprite("./sprites/arrow.png", 320, 245, 32, 32, false) {}

void Arrow::move(int y)
{
   spriteRect.y = y;
}
