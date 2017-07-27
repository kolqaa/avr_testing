#include <stdio.h>
#include <string.h>

/*Возможно в этом задании нам показали что адресс стандартных функций расспологается в памяти так же как и остальные данные, затрудняюсь ответить*/

int main(void)
{
  unsigned char *pc;

  pc = (unsigned char *)&memset;
  pc = (unsigned char *)0x90;
  printf("%p\n", &pc);
}
