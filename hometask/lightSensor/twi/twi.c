#include "twi.h"

void     TWI_init(void) {
  TWBR = 0x48; //((F_CPU/100000)-16)/2; Bit rate generator
}

void TWI_start(void) {
  TWCR = (_BV(TWINT)) | (_BV(TWSTA)) | (_BV(TWEN)) | (_BV(TWIE));
  while (!(TWCR & (1 << TWINT)))
    ;
}

void TWI_stop(void) {
  TWCR = (_BV(TWINT)) | (_BV(TWSTO)) | (_BV(TWEN));
}

void TWI_send_SLA(int mode) {
  if (mode == WRITE) {
    TWDR = SLA_W;
    TWCR = (_BV(TWINT)) | (_BV(TWEN));
    while (!(TWCR & (1 << TWINT)))
      ;
  }
  else {
    TWDR = SLA_R;
    TWCR = (_BV(TWINT)) | (_BV(TWEN));
    while (!(TWCR & (1 << TWINT)))
      ;
  }
}

void TWI_checkStatus(void) {
  u_print("Status TWSR: [");
  u_printhex(TWSR);
  u_print("]\n");
}

void TWI_sendData(unsigned char data) {
  TWDR = data;
  TWCR = (_BV(TWINT)) | (_BV(TWEN));
  while (!(TWCR & (1 << TWINT)))
    ;
}

unsigned char TWI_readByte_ACK(void) {
  TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
  while(!(TWCR & (1<<TWINT)))
    ;
  return TWDR;
}

unsigned char TWI_readByte_NACK(void) {
  TWCR = (1<<TWINT) | (1<<TWEN);
  while (!(TWCR & (1<<TWINT)))
    ;
  return TWDR;
}



