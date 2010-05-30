#ifndef _DUAL_MAIN_
#define _DUAL_MAIN_

#include <nds.h>
#include <fat.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define SCREEN_UP 1
#define SCREEN_DOWN 0

typedef struct DUAL_IMAGE DUAL_IMAGE;

struct DUAL_IMAGE
{
    	int x;
    	int y;
   	int width;
   	int height;
	char * img;
	int type;
	//int screen;
	//int bg;
};

typedef struct DUAL_STYLUS DUAL_STYLUS;

struct DUAL_STYLUS
{
    	u16 deltaX;
    	u16 deltaY;
	u16 doubleClick;
	u8 doubleClickDelay;
	u8 _clickTime;
};

extern DUAL_STYLUS_S DUAL_Stylus;

typedef struct DUAL_KEYS DUAL_KEYS;

struct DUAL_KEYS
{
	int touch
};

#include "DUAL_Draw.h"

#endif // _DUAL_MAIN_
