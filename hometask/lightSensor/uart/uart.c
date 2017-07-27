#include "usart.h"

static char *ft_strrev(char *str)
{
  int len;
  int i;
  char tmp;

  i = 0;
  if (str[i] == '-')
    i++;
  len = 0;
  while (str[len])
    len++;
  len = len - 1;
  while (len > i)
    {
      tmp = str[len];
      str[len] = str[i];
      str[i] = tmp;
      i++;
      len--;
    }
  return(str);
}

void    u_printhex(int nbr)
{
  char str[32];
  int i;
  char array[] = "0123456789ABCDEF";

  i = 0;
  if (nbr == 0)
    {
      str[0] = '0';
      str[1] = '\0';
      u_print(str);
      return ;
    }
  while (nbr != 0)
    {
      str[i] = array[nbr % 16];
      nbr = nbr / 16;
      i++;
    }
  str[i] = '\0';
  ft_strrev(str);
  u_print("0x");
  u_print(str);
  str[0] = '\0';
}


void	init_uart(void) {
  UBRR0H = 0;
  UBRR0L = 8;
  UCSR0B &= ~_BV(UCSZ02);
  UCSR0C |= _BV(UCSZ01) | _BV(UCSZ00);
  UCSR0C &= ~_BV(USBS0) & ~_BV(UPM00) & ~_BV(UPM01);
  UCSR0B |= _BV(TXEN0);
}

void  u_print(char *str) {
  size_t i;
  for (i = 0 ; str[i]; i++) {
    if (!bufferIsFull(&buffer))
      pushInBuff(&buffer, str[i]);
  }
}

void u_printchar(char c) {
  if (!bufferIsFull(&buffer))
    pushInBuff(&buffer, c);
}


void    u_printnumbers(long nb)
{
  if (nb < 0)
    {
      u_printchar('-');
      nb = -nb;
    }
  if (nb >= 10)
    {
      u_printnumbers(nb / 10);
      u_printnumbers(nb % 10);
    }
  else
    {
      u_printchar(nb + '0');
    }
}
