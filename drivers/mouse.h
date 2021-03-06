#include "../cpu/ports.h"
#include "types.h"
#include <stdbool.h>
#include "../gui/video.h"

#define PS2Leftbutton 0b00000001
#define PS2Middlebutton 0b00000100
#define PS2Rightbutton 0b00000010
#define PS2XSign 0b00010000
#define PS2YSign 0b00100000
#define PS2XOverflow 0b01000000
#define PS2YOverflow 0b10000000

void InitPS2Mouse();
void HandlePS2Mouse(uint8_t data);

static struct Point{
    long X;
    long Y;
} Point;