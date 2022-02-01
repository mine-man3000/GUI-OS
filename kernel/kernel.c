#include "../gui/video.h"
#include "util.h"
#include "../drivers/mouse.h" 

void main() 
{
    //background
    PaintDesktop(0x09);

    //has to be padded to 10 characters for whatver reason even
    //drawWindow(10, 10, 200, 9, "HELLO                ", 0x0F);
    //drawWindow(20, 20, 200, 6, "hey mom how are you ", 0x0F);
    
    InitPS2Mouse();

    //taskbar
    //x, y, width, height, color
    while (1)
    {
        uint8_t mouseData = port_word_in(0x60);
        uint8_t mouseDataOld = port_word_in(0x60);
        if(mouseData != mouseDataOld)
        {
            //PaintDesktop(0x09);
            //drawWindow(20, 20, 200, 9, "hey mom how are you ", 0x0F);
            //drawWindow(10, 10, 200, 100, "hello mom how are you", 0x0F);
            HandlePS2Mouse(mouseData);
        }
    }
}