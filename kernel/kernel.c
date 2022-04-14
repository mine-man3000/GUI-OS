#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include "../gui/video.h"
#include "../drivers/mouse.h"

void kernel_main() {
    isr_install();
    irq_install();

    //background
    PaintDesktop(0x09);

    kprint_at("TEST", 0, 0);

    drawWindow(10, 10, 10, 10, "HELLO WORLD", 0x0F);

    //drawWindow(15, 15, 200, 9, "HELLO WORLD", 0x0F);


    drawRect(10, 10, 10, 10, 0xAA);

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
            //drawRect(100, 100, 10, 10, 0xAA);
            HandlePS2Mouse(mouseData);
            drawWindow(10, 10, 200, 9, "HELLO WORLD", 0x0F);            
        }
    }

}

void user_input(char *input) {
    return;
    //if (strcmp(input, "END") == 0) {
    //    kprint("Stopping the CPU. Bye!\n");
    //    asm volatile("hlt");
    //} else if (strcmp(input, "PAGE") == 0) {
    //    /* Lesson 22: Code to test kmalloc, the rest is unchanged */
    //    uint32_t phys_addr;
    //    uint32_t page = kmalloc(1000, 1, &phys_addr);
    //    char page_str[16] = "";
    //    hex_to_ascii(page, page_str);
    //    char phys_str[16] = "";
    //    hex_to_ascii(phys_addr, phys_str);
    //    kprint("Page: ");
    //    kprint(page_str);
    //    kprint(", physical address: ");
    //    kprint(phys_str);
    //    kprint("\n");
    //}
    //kprint("You said: ");
    //kprint(input);
    //kprint("\n> ");
}
