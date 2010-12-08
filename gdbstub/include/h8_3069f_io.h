/*
 * H8 3069F I/O Address definition header
 */

#ifndef _H8_3069F_IO_H_
#define _H8_3069F_IO_H_

typedef struct sci_registers {
	/* Serial Mode Register */
	struct {
		unsigned C_A    : 1;    /* Communication mode: 0=調歩同期式, 1=クロック同期式 */
		unsigned CHR    : 1;    /* Character Length: 0=8bit, 1=7bit */
		unsigned PE     : 1;    /* Parity and check: 0=disable, 1=enable*/
		unsigned O_E    : 1;    /* Parity mode: 0=even, 1=odd */
		unsigned STOP   : 1;    /* Stop bit length: 0=1bit, 1=2bit */
		unsigned MP     : 1;    /* Multiprocessor: 0=disable, 1=enable */
		unsigned CKS    : 2;    /* Clock select: 0=1, 1=1/4, 2=1/16, 3=1/64*/
	} SMR;	

	/* Bit Rate Register */
	unsigned char BRR;

	/* Serial Control Register */
	struct {
		unsigned TIE    : 1;    /* Transmit (Data Empty) Interrupt Enable */
		unsigned RIE    : 1;    /* Receive Interrupt Enable */
		unsigned TE     : 1;    /* Transmit Enable */
		unsigned RE     : 1;    /* Receive Enable */
		unsigned MPIE   : 1;    /* Multi Processor Interrupt Enable */
		unsigned TEIE   : 1;    /* Transmit End Interrupt Enable */
		unsigned CKE    : 2;    /* Clock Enable */
	} SCR; 	

	/* Transmit Data Register */
	unsigned char TDR;

	/* Serial Status Register */
	struct {
		unsigned TDRE   : 1;    /* TDR(Transmit Data Register) Empty*/
		unsigned RDRF   : 1;    /* RDR(Receive Data Register) Empty */
		unsigned ORER   : 1;    /* Over Run Error */
		unsigned FER    : 1;    /* Flaming Error */
		unsigned PER    : 1;    /* Parity Error */
		unsigned TEND   : 1;    /* Transmit End */
		unsigned MPB    : 1;    /* Multi Processor Bit */
		unsigned MPBT   : 1;    /* Multi Processor Bit Transfer */
	} SSR; 	

	/* Receive Data Register */
	unsigned char RDR;

	/* Smart Card Mode Register */
	struct {
		unsigned pad0   : 4;
		unsigned SDIR   : 1;    /* Smartcard Data transfer DIrection */
		unsigned SINV   : 1;    /* Smartcard Data Invert */
		unsigned pad1   : 1;
		unsigned SMIF   : 1;    /* Smartcard Mode Interface Mode: 0=SCI, 1=Smartcard */
	} SCMR;	
} sci_registers_t;

#define SCI_BAUD_9600	(9600)
#define SCI_BAUD_19200	(19200)
#define SCI_BAUD_38400	(38400)

#define SCI_CHARLEN_7	(7)
#define SCI_CHARLEN_8	(8)

#define SCI_PARITY_DISABLED	(0)
#define SCI_PARITY_ENABLED	(1)

#define SCI_INT_TIE	(1<<0)
#define SCI_INT_RIE	(1<<1)
#define SCI_INT_MPIE	(1<<2)
#define SCI_INT_TEIE	(1<<3)

/* Registers  */
#define SCI1	(*(volatile sci_registers_t*)(0xFFFFB8))

#endif
