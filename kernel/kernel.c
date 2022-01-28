#include "../gui/video.h"
#include "util.h" 

void main() 
{
    //background
    PaintDesktop(0x09);

    drawWindow(10, 10, 200, 100, "HELLO     ", 0x0F);

    //taskbar
    //x, y, width, height, color
    //draw_rect(2, 182, 16, 16, 0x20);

    while (1)
    {
        //drawString("Hello World", 10, 16);
    }
}