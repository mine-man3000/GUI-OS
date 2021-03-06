#include "video.h"
#include "../libc/mem.h"
#include "icon.h"
#include "ascii.h"
#include <stdbool.h>

bool MouseDrawn;

int width       = 320;
int height      = 200;
int pitch       = 2560;
int depth       = 8;
int pixelwidth  = 8;

uint8_t g_BackBuffer[320*200];

uint32_t MouseCursorBuffer[16 * 16];
uint32_t MouseCursorBufferAfter[16 * 16];

unsigned char getPixel(int pos_x, int pos_y)
{
    unsigned char* location = (unsigned char*)0xA0000 + WIDTH * pos_y + pos_x;
    return location;
}

uint8_t drawRect(int startx, int starty, int width, int height, unsigned char VGA_COLOR)
{
    int endx = startx + width;
    int endy = starty + height;

    for (int i = startx; i < endx; i++)
    {
        for (int j = starty; j < endy; j++)
        {
            g_BackBuffer[i + j * width] = VGA_COLOR;
        }        
    }
    return g_BackBuffer;
    //memory_copy(g_BackBuffer, (void*)0xA0000, sizeof(g_BackBuffer));
}


uint8_t drawLine(int startx, int starty, int width, unsigned char VGA_COLOR)
{
    int endx = startx + width;

    for (int i = startx; i < endx; i++)
    {
        g_BackBuffer[i + starty * width] = VGA_COLOR;
    }
    return g_BackBuffer;
    //memory_copy(g_BackBuffer, (void*)0xA0000, sizeof(g_BackBuffer));
}

void PaintDesktop(int VGA_COLOR)
{
    //fill the background of the desktop
    drawRect(0, 0 , WIDTH, HEIGHT - 20, VGA_COLOR);
    drawRect(0, 180, WIDTH, 20, 0x07);
    drawImage(start, 2, 182);
    memory_copy(g_BackBuffer, (void*)0xA0000, sizeof(g_BackBuffer));
}

void drawWindow(int x, int y, int width, int height, char* name, unsigned char VGA_COLOR)
{
    drawRect(x, y, width, height, 0x17);
    drawRect(x + 1, y, width - 2, height - 1, VGA_COLOR);
    drawRect(x, y-3, width, 9, 0x37);
    //drawString(name, x + 2, y - 1);
    drawImage(close, x + width - 7, y - 1);
    memory_copy(g_BackBuffer, (void*)0xA0000, sizeof(g_BackBuffer));
}

uint8_t drawLetter(char *letter, int startx, int starty)
{
    int x = startx;
    int y = starty;
    for (int i = 0; i < 29; i++)
    {
        if (letter[i] == 2)
        {
            x = startx;
            y++;
        }
        if (letter[i] == 1)
        {
            g_BackBuffer[i + starty * width] = 0x00;
            x++;
        }
        if (letter[i] == 0)
        {
            x++;
        }
    }
    return g_BackBuffer;
    //memory_copy(g_BackBuffer, (void*)0xA0000, sizeof(g_BackBuffer));
}

uint8_t drawImage(char *icon, int posx, int posy)
{
    int x = posx;
    int y = posy;
    for (int i = 0; icon[i] != 3; i++)
    {
        if(icon[i] == 2)
        {
            x = posx;
            y++;
        }
        else
        {
            g_BackBuffer[x + y * width] = icon[i];
            x++;
        }
    }
    return g_BackBuffer;
    //memory_copy(g_BackBuffer, (void*)0xA0000, sizeof(g_BackBuffer));
}


void drawCursor(long X, long Y)
{
    PaintDesktop(0x09);
    uint8_t buffer = drawRect(X, Y, 3, 3, 0x00);
    memory_copy(buffer, (void*)0xA0000, sizeof(buffer));
}

void drawString(char* str, int startx, int starty)
{
    //Better?
}