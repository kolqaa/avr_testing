#ifndef MAIN_H
# define MAIN_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <inttypes.h>
#include <util/delay.h>
#include "uart/usart.h"
#include "twi/twi.h"
#include "bh1750/bh1750.h"

#define WRITE 1
#define READ 0

#define BUFF_SIZE 256
#define BUFF_MASK (BUFF_SIZE - 1)

typedef struct  buffer {
  char          array[BUFF_SIZE];
  uint16_t      size;
  uint8_t       read;
  uint8_t       write;
}               buffer_t;


extern buffer_t buffer;

uint8_t         init_buffer(buffer_t *buffer, uint16_t size);
uint8_t         bufferIsFull(buffer_t *buffer);
uint8_t         bufferIsEmpty(buffer_t *buffer);
void            pushInBuff(buffer_t *buffer, char data);
char            popFromBuff(buffer_t *buffer);
void            clearBuffer(buffer_t *buffer);

#endif
