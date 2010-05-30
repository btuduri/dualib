#include "DUAL.h"

u16 * DUAL_BG16[2];
u32 * DUAL_BG32[2];

DUAL_COLOR DUAL_NewColor(u8 r, u8 g, u8 b)
{
	return DUAL_COLOR color = {r, g, b, RGB15(r, g, b)};
}

void DUAL_Init16BitBg(u8 screen, u8 bg)
{
	_REG16(REG_BGSCREEN(screen)) &= ~7;
	_REG16(REG_BGSCREEN(screen)) |= (0x100 << (3)) | MODE_3_2D;
	DUAL_BG16[screen] = (u16*)(0x06000000 + (0x200000 *  screen) + 128 * 256);
	DUAL_BG32[screen] = (u32*)DUAL_BG16[screen];
	dmaFillWords(0, (void*)DUAL_BG16[screen], 256*192*2);
	_REG16(REG_BGCNT(screen, 3)) = bg_priority | BG_BMP16_256x256 | BG_BMP_BASE(2);
}

void DUAL_Put16BitPixel(u8 screen, u16 x, u16 y, u16 color)//DUAL_COLOR color)
{
	(u16*)(BG_BMP_RAM(0) + (y << 8) + x) = color;//.RGB15;
	//DUAL_BG16[screen][x + (y << 8)] = color;
	
}
