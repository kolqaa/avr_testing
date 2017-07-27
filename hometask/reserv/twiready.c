#include "main.h"


void     TWI_init(void) {
  TWBR = 0x48; //((F_CPU/100000)-16)/2; Bit rate generator
}

void TWI_wait(void) {
  while (!(TWCR & (1 << TWINT ))
	 ;
}

void TWI_start(void) {
  TWCR = (_BV(TWINT)) | (_BV(TWSTA)) | (_BV(TWEN)) | (_BV(TWIE));
  while (!(TWCR & (1 << TWINT)))
    ;
  u_print("TWI START\n");
}

void TWI_stop(void) {
  TWCR = (_BV(TWINT)) | (_BV(TWSTO)) | (_BV(TWEN));
  u_print("TWI STOP\n");
}

void TWI_send_SLA(int mode) {
  if (mode == WRITE) {
    u_print("TWI SEND [SLA+W]\n");
    TWDR = 0b01000110;
    TWCR = (_BV(TWINT)) | (_BV(TWEN));
    while (!(TWCR & (1 << TWINT)))
      ;
  }
  else {
    u_print("TWI SEND [SLA+R]\n");
    TWDR = 0b01000111;
    TWCR = (_BV(TWINT)) | (_BV(TWEN));
    while (!(TWCR & (1 << TWINT)));
  }
}


void TWI_checkStatus(void) {
  u_print("Status TWSR: [");
  u_printhex(TWSR);
  u_print("]\n");
}

void TWI_sendData(unsigned char c) {
  TWDR = c;
  TWCR = (_BV(TWINT)) | (_BV(TWEN));
  while (!(TWCR & (1 << TWINT)))
    ;
  u_print("TWI [SEND DATA]\n");
}
