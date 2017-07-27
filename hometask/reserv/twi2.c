#include "main.h"
#include <stdio.h>


void     TWI_init(void) {
  TWBR = 0x48; //((F_CPU/100000)-16)/2; Bit rate generator
}

void TWI_wait(void) {
  while (!(TWCR & (1 << TWINT )))
    ;
  TWCR = _BV(TWINT);
}

uint8_t TWI_start(void) {
  //  uint8_t status = TWI_SUCCESS;
  
  TWCR = (_BV(TWINT)) | (_BV(TWSTA)) | (_BV(TWEN));// | (_BV(TWIE));
  printf("before wait\n");

  TWI_wait();
  printf("after wait\n");
    //status = TWSR & TWSR_MASK;
  //if ((status != TWI_START) && (status != TWI_REP_START))
  //return status;
  //   u_print
  printf("TWI START\n");
  return TWI_SUCCESS;
}

void TWI_stop(void) {
  TWCR = (_BV(TWINT)) | (_BV(TWSTO)) | (_BV(TWEN));
  // u_print
  printf("TWI STOP\n");
}

uint8_t TWI_send_SLA(int mode) {
  uint8_t status;
  if (mode == WRITE) {
    //  TWI_wait();
    TWDR = SLA_W;
    TWCR = (_BV(TWINT)) | (_BV(TWEN));
    TWI_wait();
    status = TWSR & TWSR_MASK;
    if (status != TWI_SLA_W_ACK)
      return status;
    // u_print
    printf("TWI SEND [SLA+W]\n");
    // TWCR |= _BV(TWINT);
    return TWI_SUCCESS;
  }
  else {
    TWDR = SLA_R;
    TWCR = (_BV(TWINT)) | (_BV(TWEN));
    TWI_wait();
    status = TWSR & TWSR_MASK;
    if (status != TWI_SLA_R_ACK)
      return status;
    // u_print
    printf("TWI SEND [SLA+R]\n");
    //TWCR |= _BV(TWINT);
    return TWI_SUCCESS;
  }
}


void TWI_checkStatus(void) {
  u_print("Status TWSR: [");
  u_printhex(TWSR);
  u_print("]\n");
}

uint8_t TWI_sendData(unsigned char data) {
  uint8_t status; 
  //TWI_wait();
  TWDR = data;
  TWCR = (_BV(TWINT)) | (_BV(TWEN));
  TWI_wait();
  status = TWSR & TWSR_MASK;
  if (status != TWI_DATA_W_ACK)
    return status;
  //u_print
  printf("TWI [SEND DATA]\n");
  TWCR |= _BV(TWINT);
  return TWI_SUCCESS;
}
