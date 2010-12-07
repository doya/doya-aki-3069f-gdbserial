/*
 * H8 3069F I/O Address definition header
 */

#ifndef _H8_3069F_IO_H_
#define _H8_3069F_IO_H_

#define SCI_BAUD_9600	(9600)
#define SCI_BAUD_19200	(19200)
#define SCI_BAUD_38400	(38400)

#define SCI_CHARLEN_7	(7)
#define SCI_CHARLEN_8	(8)

#define SCI_PARITY_DISABLED	(0)
#define SCI_PARITY_ENABLED	(1)

/* SCI1 Registers       Address                                   Register_name              R/W     Default value */
/* --------------------------------------------------------------------------------- */
#define SCI1_SMR        (*(volatile unsigned char*)(0xFFFFB8)) /* Serial Mode Register       R/W     0x00          */ 
#define SCI1_BRR        (*(volatile unsigned char*)(0xFFFFB9)) /* Bit Rate Register          R/W     0xFF          */ 
#define SCI1_SCR        (*(volatile unsigned char*)(0xFFFFBA)) /* Serial Control Register    R/W     0x00          */ 
#define SCI1_TDR        (*(volatile unsigned char*)(0xFFFFBB)) /* Transmit Data Register     R/W     0xFF          */ 
#define SCI1_SSR        (*(volatile unsigned char*)(0xFFFFBC)) /* Serial Status Register     R/(W)   0x00          */ 
#define SCI1_RDR        (*(volatile unsigned char*)(0xFFFFBD)) /* Receive Data Register      R       0x84          */ 
#define SCI1_SCMR       (*(volatile unsigned char*)(0xFFFFBE)) /* Smart Card Mode Register   R/W     0xF2          */ 

#endif
