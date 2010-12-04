/*
 * H8 3069F I/O Address definition header
 */

#ifndef _H8_3069F_IO_H_
#define _H8_3069F_IO_H_

/* SCI1 Registers       Address     Register_name              R/W     Default value */
/* --------------------------------------------------------------------------------- */
#define SCI1_SMR        0xFFFFB8 /* Serial Mode Register       R/W     0x00          */ 
#define SCI1_BRR        0xFFFFB9 /* Bit Rate Register          R/W     0xFF          */ 
#define SCI1_SCR        0xFFFFBA /* Serial Control Register    R/W     0x00          */ 
#define SCI1_TDR        0xFFFFBB /* Transmit Data Register     R/W     0xFF          */ 
#define SCI1_SSR        0xFFFFBC /* Serial Status Register     R/(W)   0x00          */ 
#define SCI1_RDR        0xFFFFBD /* Receive Data Register      R       0x84          */ 
#define SCI1_SCMR       0xFFFFBE /* Smart Card Mode Register   R/W     0xF2          */ 

#endif