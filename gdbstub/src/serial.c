#include "h8_3069f_io.h"

/*
 * @func serial_init
 * 
 * initialize SCI1
 */
void serial_init(int baudrate, int charlen, int parity)
{
	int i;

	/* まず送受信機能をオフにする */
#if 0
	SCI1.SCR.BIT.TE = 0;
	SCI1.SCR.BIT.RE = 0;
#else
	SCI1.SCR.BYTE &= ~0x30; /* TE = 0, RE = 0 */
#endif

	/* LSPファースト設定(?) */
	SCI1.SCMR.SDIR = 0;

	/* シリアルインタフェース設定(初期値でOK) */
	SCI1.SCMR.SMIF = 0;

	/* クロックソース設定(ボージェネレータからの内部クロック) */
	SCI1.SCR.BIT.CKE = 0;

	/* 調歩同期式モード設定 */
	SCI1.SMR.C_A = 0;

	/* キャラクタレンス設定 */
	switch(charlen) {
	case SCI_CHARLEN_7:
		SCI1.SMR.CHR = 1;
		break;
	case SCI_CHARLEN_8:
	default:
		SCI1.SMR.CHR = 0;
		break;
	}

	/* パリティビット設定 */
	switch(parity) {
	case SCI_PARITY_ENABLED:
		SCI1.SMR.PE = 1;
		break;
	case SCI_PARITY_DISABLED:
	default:
		SCI1.SMR.PE = 0;
		break;
	}

	/* ボーレート設定 */
	switch(baudrate) {
	case SCI_BAUD_38400:
		SCI1.SMR.CKS = 0;
		SCI1.BRR = 15;
		break;
	case SCI_BAUD_19200:
		SCI1.SMR.CKS = 0;
		SCI1.BRR = 32;
		break;
	case SCI_BAUD_9600:
	default:
		SCI1.SMR.CKS = 0;
		SCI1.BRR = 64;
		break;
	}

	/* wait more than 1 bit time */
	for(i=0; i<10000; i++) {
		;
	}

	/* 送受信機能をオンにする */
#if 0
	SCI1.SCR.BIT.TE = 1;
	SCI1.SCR.BIT.RE = 1;
#else
	SCI1.SCR.BYTE |= 0x30; /* TE = 1, RE = 1 */
#endif

	return;
}


/*
 * @func serial_disable_int
 * 
 * disable interrupts of SCI1
 */
void serial_disable_int_all(int flag)
{
	if (flag & SCI_INT_TIE) {
		SCI1.SCR.BIT.TIE  = 0;
	}
	if (flag & SCI_INT_RIE) {
		SCI1.SCR.BIT.RIE  = 0;
	}
	if (flag & SCI_INT_MPIE) {
		SCI1.SCR.BIT.MPIE = 0;
	}
	if (flag & SCI_INT_TEIE) {
		SCI1.SCR.BIT.TEIE = 0;
	}

	return;
}

/*
 * @func serial_enable_int
 * 
 * enable interrupts of SCI1
 */
void serial_enable_int(int flag)
{
	if (flag & SCI_INT_TIE) {
		SCI1.SCR.BIT.TIE  = 1;
	}
	if (flag & SCI_INT_RIE) {
		SCI1.SCR.BIT.RIE  = 1;
	}
	if (flag & SCI_INT_MPIE) {
		SCI1.SCR.BIT.MPIE = 1;
	}
	if (flag & SCI_INT_TEIE) {
		SCI1.SCR.BIT.TEIE = 1;
	}

	return;
}

void serial_puts(char *data)
{
	while (data && *data) {
		while(SCI1.SSR.TDRE != 1) {
			;
		}

		SCI1.TDR = *data;
		data++;
	}

	while(SCI1.SSR.TEND != 1) {
		;
	}
	
	return;
}

