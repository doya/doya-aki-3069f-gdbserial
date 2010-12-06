#include "h8_3069f.h"

/*
 * @func serial_disable_int
 * 
 * disable all interrupts of SCI1
 */
void serial_disable_int(void)
{
	unsigned char sci1_scr = SCI1_SCR;

	sci1_scr &= 0x33;
	SCI1_SCR = sci1_scr;

	return;
}

/*
 * @func serial_enable_int
 * 
 * enable receive interrupts of SCI1
 */
void serial_enable_int(void)
{
	unsigned char sci1_scr = SCI1_SCR;

	sci1_scr |= 0x40;
	SCI1_SCR = sci1_scr;

	return;
}
