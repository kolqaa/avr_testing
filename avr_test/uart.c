#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

int  main(void)
{
  const uint16_t ubrr = F_CPU/16/115200 - 1; //115200 F_CPU/16/bauderate - 1; //USCRn
  UBRR0H = ubrr >> 8;
  UBRR0L = ubrr & 0xff;

  UCSR0B = (0 << RXEN0) | (1 << TXEN0);

  //set frame format: 8data, 1stop bit
  UCSR0C = (0 << USBS0) | (3 << UCSZ00);


  UDR0 = 'd';
  while (1) {
  }
  
  return 0;
}
