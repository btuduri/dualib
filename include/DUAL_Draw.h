#ifndef _DUAL_DRAW_
#define _DUAL_DRAW_

extern u16 * DUAL_BG16[2];
extern u32 * DUAL_BG32[2];

typedef struct DUAL_COLOR DUAL_COLOR;

struct DUAL_COLOR
{
	int r;
	int g;
	int b;
	u16 RGB15;
};

#endif // _DUAL_DRAW_
