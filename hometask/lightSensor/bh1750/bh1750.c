#include "bh1750.h"

uint16_t getlux_from_bh1750_lightSensor(void) {
  uint16_t lux;
  TWI_start();
  TWI_send_SLA(READ);
  lux = TWI_readByte_ACK();
  lux <<= 8;
  lux |= TWI_readByte_NACK();
  TWI_stop();
  lux = lux/1.2;
  return (lux);
}

void init_bh1750_lightSensor(void) {
  TWI_start();
  TWI_send_SLA(WRITE);
  TWI_sendData(0b00010000);
  TWI_stop();
}
