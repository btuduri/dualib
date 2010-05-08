#include "DUAL.h"

DUAL_COLOR DUAL_NewColor(int r, int g, int b)
{
	return DUAL_COLOR color = {r, g, b, RGB15(r, g, b)};
}

void DUAL_Put16BitPixel(int x, int y, DUAL_COLOR color)
{
	*(u16*)(BG_BMP_RAM(0) + (y << 8) + x) = color.RGB15;
}
