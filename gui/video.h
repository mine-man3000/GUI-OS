#pragma once
#include "../drivers/types.h"

#define VGA_MEM 0xa0000
#define WIDTH   320
#define HEIGHT  200

void drawCursor(long X, long Y);
void putPixel(int pos_x, int pos_y, unsigned char VGA_COLOR);
void PaintDesktop();
void drawWindow(int x, int y, int width, int height, char* name, unsigned char VGA_COLOR);
void drawString(char* str, int startx, int starty);

uint8_t drawLetter(char *letter, int startx, int starty);
uint8_t drawImage(char *icon, int posx, int posy);
uint8_t drawRect(int startx, int starty, int width, int height, unsigned char VGA_COLOR);
uint8_t drawLine(int startx, int starty, int width, unsigned char VGA_COLOR);