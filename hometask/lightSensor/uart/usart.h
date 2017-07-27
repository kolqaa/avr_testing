#ifndef USART_H
# define USART_H

#include "../main.h"

void            u_printhex(int nbr);
void            u_print(char *str);
void            u_printnumbers(long nb);
void            u_printchar(char c);
void            init_uart(void);

#endif
