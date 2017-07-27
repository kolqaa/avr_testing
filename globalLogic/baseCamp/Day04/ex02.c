#include <stdio.h>
#include <string.h>

typedef void (*func)(void *, int , size_t);
volatile func memset_s;

int	main(void)
{
  memset_s = (void *)&memset;
  printf("%p\n", memset_s);
  memset_s((void*)&memset_s, 0, sizeof(memset_s));
  printf("%p\n", memset_s);
}
