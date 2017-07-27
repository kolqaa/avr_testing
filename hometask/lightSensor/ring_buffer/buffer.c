#include "../main.h"

uint8_t	init_buffer(buffer_t *buffer, uint16_t size) {
  buffer->size = size;
  buffer->read = 0;
  buffer->write = 0;
  return (1);
}

uint8_t bufferIsFull(buffer_t *buffer) {
  return ((buffer->read == (buffer->write+1)%(buffer->size)) ? 1 : 0);
}

void clearBuffer(buffer_t *buffer) {
  buffer->array[0] = '\0';
  buffer->read = 0;
  buffer->write = 0;
}

uint8_t bufferIsEmpty(buffer_t *buffer) {
  return (buffer->read == buffer->write ? 1 : 0);
}

void	pushInBuff(buffer_t *buffer, char data) {
  buffer->array[buffer->write++] = data;
  buffer->write &= BUFF_MASK;
}

char popFromBuff(buffer_t *buffer) {
  char element = buffer->array[buffer->read++];
  buffer->read &= BUFF_MASK;
  return (element);
}
