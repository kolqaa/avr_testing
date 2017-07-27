#include <stdio.h>

#define BUFFER_SIZE 256

typedef struct {
  unsigned char *buffer;
  int head;
  int tail;
  int maxLen;
} ringBuf_t;

ringBuf_t ringBufdata;
unsigned char g_buffer[BUFFER_SIZE];

int ringBufPush(ringBuf_t *c, unsigned char data)
{
  int next = c->tail + 1;
  if (next >= c->maxLen)  
    next = 0;

  if (next == c->head)
    return -1;

  c->buffer[c->tail] = data;
  c->tail = next;
  return 0;
}

int ringBufPop(ringBuf_t *c, unsigned char *data)
{
  if (c->tail == c->head) 
    return -1;          

  int next = c->head + 1;
  if(next >= c->maxLen)
    next = 0;
  *data = c->buffer[c->head]; 
  c->head = next;             
  return 0;  
}

void init_struct() {
  ringBufdata.buffer = g_buffer;
  ringBufdata.maxLen = BUFFER_SIZE;
  ringBufdata.head = 0;
  ringBufdata.tail = 0;
}

int main(void)
{
  init_struct();
  char let = 'a';
  int i = 0;

  char outdata;
  while (i < BUFFER_SIZE)
    {
      if (ringBufPush(&ringBufdata, let)) {
	printf("OUT OF SPACE IN CB\n");
      }
      i++;
      let++;
      if (let == 122)
	{
	  if (ringBufPop(&ringBufdata, &outdata))
	    printf("isempty\n");
	  let = 'a';
	}
    }
  if (ringBufPop(&ringBufdata, &outdata)) {
      printf("IS empty");
   }
  /*while (i < BUFFER_SIZE)
    {
      if (ringBufPush(&ringBufdata, let)) {
	printf("OUT OF SPACE IN CB\n");
      }
      i++;
      let++;
      if (let == 122)
	let = 'a';
      printf("(%d)\n", i);
    }
  i = 0;
  while (i < BUFFER_SIZE) {
    if (ringBufPop(&ringBufdata, &j[i]))
      {
	printf("IS EMPTY\n");
      }
    i++;
    }*/
  //printf("((%c))\n", j[254]);
}
