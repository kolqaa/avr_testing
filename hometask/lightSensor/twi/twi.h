#ifndef TWI_H
# define TWI_H

#include "../main.h"

#define SLA_W 0b01000110
#define SLA_R 0b01000111
#define TWSR_MASK 0xfc
#define TWI_SUCCESS 0xff
//master
#define TWI_START 0x08
#define TWI_REP_START 0x10
// Master Transmitter
#define TWI_SLA_W_ACK 0x18
#define TWI_SLA_W_NACK 0x20
#define TWI_DATA_W_ACK 0x28
#define TWI_DATA_W_NACK 0x30
#define TWI_ARB_W_LOST 0x38
// Master Receiver
#define TWI_ARB_W_LOST 0x38
#define TWI_SLA_R_ACK 0x40
#define TWI_SLA_R_NACK 0x48
#define TWI_DATA_R_ACK 0x50
#define TWI_DATA_R_NACK 0x58
// Misc
#define TWI_NO_STATE 0xF8
#define TWI_BUS_ERROR 0x00

void            TWI_init(void);
void            TWI_start(void);
void            TWI_stop(void);
void            TWI_send_SLA(int mode);
void            TWI_checkStatus(void);
void            TWI_sendData(unsigned char data);
unsigned char   TWI_readByte_NACK(void);
unsigned char   TWI_readByte_ACK(void);

#endif
