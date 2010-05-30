#include "DUAL.h"

void on_irq()
{
    if(IF & IRQ_VBLANK)
    {
        draw_shape(old_x, old_y, VRAM_A, RGB15(0, 0, 0));
        draw_shape(shape_x, shape_y, VRAM_A, RGB15(31, 0, 0));

        // Indique à la DS que nous gerons les interruptions VBLANK
        VBLANK_INTR_WAIT_FLAGS |= IRQ_VBLANK;
        IF |= IRQ_VBLANK;
    }
    else
    {
        // Ignore toutes les autres interruptions
        IF = IF;
    }
}

void InitInterruptHandler()
{
    IME = 0;
    IRQ_HANDLER = on_irq;
    IE = IRQ_VBLANK;
    IF = ~0;
    DISP_SR = DISP_VBLANK_IRQ;
    IME = 1;
}

void DUAL_Init()
{
	powerON(POWER_ALL);

	irqInit();
	irqEnable(IRQ_VBLANK);
	
	consoleDemoInit();
	
	videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);
}
