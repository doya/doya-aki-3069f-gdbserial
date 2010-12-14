/*
 * H8 3069F I/O Address definition header
 */

#ifndef _H8_3069F_IO_H_
#define _H8_3069F_IO_H_

typedef struct sci_registers {
	/* Serial Mode Register */
	union {
		struct {
			volatile unsigned char C_A    : 1;    /* Communication mode: 0=調歩同期式, 1=クロック同期式 */
			volatile unsigned char CHR    : 1;    /* Character Length: 0=8bit, 1=7bit */
			volatile unsigned char PE     : 1;    /* Parity and check: 0=disable, 1=enable*/
			volatile unsigned char O_E    : 1;    /* Parity mode: 0=even, 1=odd */
			volatile unsigned char STOP   : 1;    /* Stop bit length: 0=1bit, 1=2bit */
			volatile unsigned char MP     : 1;    /* Multiprocessor: 0=disable, 1=enable */
			volatile unsigned char CKS    : 2;    /* Clock select: 0=1, 1=1/4, 2=1/16, 3=1/64*/
		} BIT;	
		volatile unsigned char BYTE;
	} SMR;	

	/* Bit Rate Register */
	union {
		volatile unsigned char BYTE;
	} BRR;

	/* Serial Control Register */
	union {
		struct {
			volatile unsigned char TIE    : 1;    /* Transmit (Data Empty) Interrupt Enable */
			volatile unsigned char RIE    : 1;    /* Receive Interrupt Enable */
			volatile unsigned char TE     : 1;    /* Transmit Enable */
			volatile unsigned char RE     : 1;    /* Receive Enable */
			volatile unsigned char MPIE   : 1;    /* Multi Processor Interrupt Enable */
			volatile unsigned char TEIE   : 1;    /* Transmit End Interrupt Enable */
			volatile unsigned char CKE    : 2;    /* Clock Enable */
		} BIT; 	
		volatile unsigned char BYTE;
	} SCR; 	

	/* Transmit Data Register */
	union {
		volatile unsigned char BYTE;
	} TDR;

	/* Serial Status Register */
	union {
		struct {
			volatile unsigned char TDRE   : 1;    /* TDR(Transmit Data Register) Empty*/
			volatile unsigned char RDRF   : 1;    /* RDR(Receive Data Register) Empty */
			volatile unsigned char ORER   : 1;    /* Over Run Error */
			volatile unsigned char FER    : 1;    /* Flaming Error */
			volatile unsigned char PER    : 1;    /* Parity Error */
			volatile unsigned char TEND   : 1;    /* Transmit End */
			volatile unsigned char MPB    : 1;    /* Multi Processor Bit */
			volatile unsigned char MPBT   : 1;    /* Multi Processor Bit Transfer */
		} BIT; 	
		volatile unsigned char BYTE;
	} SSR; 	

	/* Receive Data Register */
	union {
		volatile unsigned char BYTE;
	} RDR;

	/* Smart Card Mode Register */
	union {
		struct {
			volatile unsigned char pad0   : 4;
			volatile unsigned char SDIR   : 1;    /* Smartcard Data transfer DIrection */
			volatile unsigned char SINV   : 1;    /* Smartcard Data Invert */
			volatile unsigned char pad1   : 1;
			volatile unsigned char SMIF   : 1;    /* Smartcard Mode Interface Mode: 0=SCI, 1=Smartcard */
		} BIT;	
		volatile unsigned char BYTE;
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

#define SCI_SCR_RE	(1<<4)
#define SCI_SCR_TE	(1<<5)

/* Registers  */
#define SCI1	(*(volatile sci_registers_t*)(0xFFFFB8))

#endif
