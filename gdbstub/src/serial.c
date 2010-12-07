#include "h8_3069f_io.h"

/*
 * @func serial_init
 * 
 * initialize SCI1
 */
void serial_init(int baudrate, int charlen, int parity)
{

	/* シリアルインタフェース設定(初期値でOK) */
	SCI1_SCMR = (SCI1_SCMR & 0xFE);

	/* 調歩同期式モード設定 */
	SCI1_SMR = (SCI1_SMR & 0x7F);

	/* LSPファースト設定(?) */
	SCI1_SCMR = (SCI1_SCMR & 0xF7);

	/* クロックソース設定(ボージェネレータからの内部クロック) */
	SCI1_SCR = (SCI1_SCR & 0xFC);

	/* ボーレート設定 */
	switch(baudrate) {
	case SCI_BAUD_38400:
		SCI1_SMR = (SCI1_SMR & 0x7F);
		SCI1_BRR = 15;
		break;
	case SCI_BAUD_19200:
		SCI1_SMR = (SCI1_SMR & 0x7F);
		SCI1_BRR = 32;
		break;
	case SCI_BAUD_9600:
	default:
		SCI1_SMR = (SCI1_SMR & 0x7F);
		SCI1_BRR = 64;
		break;
	}

	/* キャラクタレンス設定 */
	switch(charlen) {
	case SCI_CHARLEN_7:
		SCI1_SMR = (SCI1_SMR | 0x40);
		break;
	case SCI_CHARLEN_8:
	default:
		SCI1_SMR = (SCI1_SMR & 0xBF);
		break;
	}

	/* パリティビット設定 */
	switch(parity) {
	case SCI_PARITY_ENABLED:
		SCI1_SMR = (SCI1_SMR | 0x20);
		break;
	case SCI_PARITY_DISABLED:
	default:
		SCI1_SMR = (SCI1_SMR & 0xDF);
		break;
	}

	return;
}


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
