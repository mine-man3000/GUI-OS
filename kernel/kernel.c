#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include "../gui/video.h"
#include "../drivers/mouse.h"


void kernel_main() {
    isr_install();
    __asm__ ("sti");
    irq_install();

    PaintDesktop(0x09);

    InitPS2Mouse();

    while (1)
    {
        uint8_t mouseData = port_word_in(0x60);
        uint8_t mouseDataOld = port_word_in(0x60);
     
        HandlePS2Mouse(mouseData);
     
        //if(mouseData != mouseDataOld)
        //{
        //    HandlePS2Mouse(mouseData);
        //    PaintDesktop(0x09);
        //}
    }
}

void user_input(char *input) {
    return;
}