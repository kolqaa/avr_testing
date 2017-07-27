#include "main.h"
#include <util/delay.h>

#define WRITE 1
#define READ 0
#define I2C_STATUS_MASK                 0xF8
#define START_COND_TRANSMITTED          0x08
#define REPEATED_START_COND_TRANSMITTED 0x10
#define SLA_W_TRANSMITTED_ACK_RECEIVED  0x18
#define DATA_TRANSMITTED_ACK_RECEIVED   0x28
#define SLA_R_TRANSMITTED_ACK_RECEIVED  0x40
#define DATA_RECEIVED_ACK_RETURNED      0x50
#define DATA_RECEIVED_NACK_RETURNED     0x58
buffer_t buffer;

ISR(USART0_UDRE_vect) {
  if (!bufferIsEmpty(&buffer))
    UDR0 = popFromBuff(&buffer);
  else
    UCSR0B &= ~_BV(UDRIE0);
}

static void	TWI_init(void) {
  TWBR = 0x48; //((F_CPU/100000)-16)/2; Bit rate generator
}

static void TWI_start(void) {
  /*TWINT interrupt flag enable, TWSTA start bit, Bit accept to work TWI*/
  TWCR = (_BV(TWINT)) | (_BV(TWSTA)) | (_BV(TWEN)) | (_BV(TWIE));
  /*wait until TWSTA is would be equal to 1*/
  while (!(TWCR & (1 << TWINT)))
    ;
   u_print("TWI START [Succesfully]\n");
}

static void TWI_stop(void) {
  TWCR = (_BV(TWINT)) | (_BV(TWSTO)) | (_BV(TWEN));
  u_print("TWI STOP [Succesfully]\n");
}

static void TWI_send_SLA(int mode) {
  if (mode == WRITE) {
    u_print("TWI SEND [SLA+W]\n");
    TWDR = 0b01000110;
    TWCR = (_BV(TWINT)) | (_BV(TWEN));
    while (!(TWCR & (1 << TWINT)))
      ;
    //    TWCR |= _BV(TWINT);
  }
  else {
    u_print("TWI SEND [SLA+R]\n");
    TWDR = 0b01000111;
    TWCR = (_BV(TWINT)) | (_BV(TWEN));
    while (!(TWCR & (1 << TWINT)));
    //    TWCR |= _BV(TWINT);
  }
}

static void TWI_checkStatus(void) {
  u_print("Status TWSR: [");
  u_printhex(TWSR);
  u_print("]\n");
}

static void TWI_sendData(unsigned char c) {
  u_print("TWI [SEND DATA]\n");
  TWDR = c;
  TWCR = (_BV(TWINT)) | (_BV(TWEN));
  while (!(TWCR & (1 << TWINT)))
	 ;
  TWCR |= _BV(TWINT);
  u_print("TWI [SEND DATA -> END]\n");
}


ISR(TWI_vect) {
  if (TWSR & 0x08) {
    u_print("START [OK]");
    TWI_send_SLA(WRITE);
    TWI_checkStatus();
      if (TWSR & 0x18){
	u_print("SLA+W [OK]");
	TWI_sendData(0b00000001);
	TWI_checkStatus();
      }
  }
  TWCR = _BV(TWINT);
 }

int	main(void) {

  DDRB |= _BV(PB7);
  PORTB &= ~(_BV(PB7));
  cli();
  
  init_buffer(&buffer, BUFF_SIZE);
  init_uart();
  TWI_init();
  TWI_start();
  sei();
  
  //
  //TWI_checkStatus();
  //TWI_send_SLA(WRITE);
  //TWI_checkStatus();
  //TWI_sendData(0b00010000); //TURN ON SENSOR
  //TWI_checkStatus();
  // TWI_stop();
  //TWI_checkStatus();
  /*    TWI_sendData(0b00010000); //Start measurment
	TWI_checkStatus();*/
    
  u_print("Init done");
  while (1) {
    if (!bufferIsEmpty(&buffer))
      UCSR0B |= _BV(UDRIE0);
  }
}
