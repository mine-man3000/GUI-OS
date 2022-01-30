#include "../gui/video.h"
#include "util.h" 

void main() 
{
    //background
    PaintDesktop(0x09);

    //has to be padded to 10 characters for whatver reason even
    drawWindow(10, 10, 200, 100, "HELLO     ", 0x0F);

    //taskbar
    //x, y, width, height, color
    while (1)
    {
        //drawString("Hello World", 10, 16);
    }
}