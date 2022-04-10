#include "video.h"
#include "../libc/mem.h"
#include "icon.h"
#include "ascii.h"
#include <stdbool.h>

bool MouseDrawn;

int width       = 320;     //pixels horizontally                   (vesa = 1024 )  (vga = 320)
int height      = 200;      //pixels vertically                     (vesa = 786  )  (vga = 200)
int pitch       = 2560;    //width*pixelwidth                      (vesa = 16384)  (vga = 5120)
int depth       = 8;       //how many bits of color                (vesa = 16)     (vga = 8)
int pixelwidth  = 8;       //how many bytes to go one pixel over   (vesa = 16)     (vga = 8)

uint8_t g_BackBuffer[320*200];

uint32_t MouseCursorBuffer[16 * 16];
uint32_t MouseCursorBufferAfter[16 * 16];

void putPixel(int pos_x, int pos_y, unsigned char VGA_COLOR)
{
    g_BackBuffer[pos_x + pos_y * width] = VGA_COLOR;
    memory_copy(g_BackBuffer, (void*)0xA0000, sizeof(g_BackBuffer));
    //unsigned char* location = (unsigned char*)0xA0000 + WIDTH * pos_y + pos_x;
    //*location = VGA_COLOR;
}

unsigned char getPixel(int pos_x, int pos_y)
{
    unsigned char* location = (unsigned char*)0xA0000 + WIDTH * pos_y + pos_x;
    return location;
}

void drawRect(int startx, int starty, int width, int height, unsigned char VGA_COLOR)
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
    memory_copy(g_BackBuffer, (void*)0xA0000, sizeof(g_BackBuffer));
}


void drawLine(int startx, int starty, int width, unsigned char VGA_COLOR)
{
    int endx = startx + width;

    for (int i = startx; i < endx; i++)
    {
        g_BackBuffer[i + starty * width] = VGA_COLOR;
    }
    memory_copy(g_BackBuffer, (void*)0xA0000, sizeof(g_BackBuffer));
}

void PaintDesktop(int VGA_COLOR)
{
    //fill the background of the desktop
    drawRect(0, 0 , WIDTH, HEIGHT, VGA_COLOR);
    drawRect(0, 180, 320, 20, 0x07);
    //drawImage(start, 2, 182);
}

void drawWindow(int x, int y, int width, int height, char* name, unsigned char VGA_COLOR)
{
    drawRect(x, y, width, height, 0x17);
    drawRect(x + 1, y, width - 2, height - 1, VGA_COLOR);
    drawRect(x, y-3, width, 9, 0x37);
    //drawString(name, x + 2, y - 1);
    //drawImage(close, x + width - 7, y - 1);
}

void drawLetter(char *letter, int startx, int starty)
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
}

void drawImage(char *icon, int posx, int posy)
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
}


void drawCursor(long X, long Y)
{
    PaintDesktop(0x09);
    drawRect(X, Y, 3, 3, 0x00);
}

void drawString(char* str, int startx, int starty)
{
    int x = startx; 
    for (int i = 0; str[i] != '\0'; i++)
    {   
        if (str[i] == 'A' || str[i] == 'a')
        {
            drawLetter(A, x, starty);
        }
        if (str[i] == 'B' || str[i] == 'b')
        {
            drawLetter(B, x, starty);
        }
        if (str[i] == 'C' || str[i] == 'c')
        {
            drawLetter(C, x, starty);
        }
        if (str[i] == 'D' || str[i] == 'd')
        {
            drawLetter(D, x, starty);
        }
        if (str[i] == 'E' || str[i] == 'e')
        {
            drawLetter(E, x, starty);
        }
        if (str[i] == 'F' || str[i] == 'f')
        {
            drawLetter(F, x, starty);
        }
        if (str[i] == 'G' || str[i] == 'g')
        {
            drawLetter(G, x, starty);
        }
        if (str[i] == 'H' || str[i] == 'h')
        {
            drawLetter(H, x, starty);
        }
        if (str[i] == 'I' || str[i] == 'i')
        {
            drawLetter(I, x, starty);
        }
        if (str[i] == 'J' || str[i] == 'j')
        {
            drawLetter(J, x, starty);
        }
        if (str[i] == 'K' || str[i] == 'k')
        {
            drawLetter(K, x, starty);
        }
        if (str[i] == 'L' || str[i] == 'l')
        {
            drawLetter(L, x, starty);
        }
        if (str[i] == 'M' || str[i] == 'm')
        {
            drawLetter(M, x, starty);
        }
        if (str[i] == 'N' || str[i] == 'n')
        {
            drawLetter(N, x, starty);
        }
        if (str[i] == 'O' || str[i] == 'o')
        {
            drawLetter(O, x, starty);
        }
        if (str[i] == 'P' || str[i] == 'p')
        {
            drawLetter(P, x, starty);
        }
        if (str[i] == 'Q' || str[i] == 'q')
        {
            drawLetter(Q, x, starty);
        }
        if (str[i] == 'R' || str[i] == 'r')
        {
            drawLetter(R, x, starty);
        }
        if (str[i] == 'S' || str[i] == 's')
        {
            drawLetter(S, x, starty);
        }
        if (str[i] == 'T' || str[i] == 't')
        {
            drawLetter(T, x, starty);
        }
        if (str[i] == 'U' || str[i] == 'u')
        {
            drawLetter(U, x, starty);
        }
        if (str[i] == 'V' || str[i] == 'v')
        {
            drawLetter(V, x, starty);
        }
        if (str[i] == 'W' || str[i] == 'w')
        {
            drawLetter(W, x, starty);
        }
        if (str[i] == 'X' || str[i] == 'x')
        {
            drawLetter(X, x, starty);
        }
        if (str[i] == 'Y' || str[i] == 'y')
        {
            drawLetter(Y, x, starty);
        }
        if (str[i] == 'Z' || str[i] == 'z')
        {
            drawLetter(Z, x, starty);
        }
        if (str[i] == ' ')
        {
            drawLetter(space, x, starty);
        }
        x += 6;        
    }
}