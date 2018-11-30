#include <stdio.h>
#include <string.h>

int main(void)
{
  unsigned char *pc;

  pc = (unsigned char *)&memset;
  pc = (unsigned char *)0x90;
  printf("%p\n", &pc);
}
