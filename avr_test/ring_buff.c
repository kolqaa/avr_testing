#include <stdio.h>
#include <stdlib.h>
#include "ringbuff.h"

int	init_buffer(buffer_t *buffer, int size) {
  buffer->size = size;
  buffer->read = 0;
  buffer->write = 0;
  buffer->array = (char *)malloc(sizeof(buffer->array) * size);
  if (buffer->array == NULL)
    return (0);
  return (1);
}

int bufferIsFull(buffer_t *buffer) {
  return ((buffer->read == (buffer->write+1)%(buffer->size)) ? 1 : 0);
}

int bufferIsEmpty(buffer_t *buffer) {
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
