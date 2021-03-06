#include "main.h"
#include <inttypes.h>

buffer_t buffer;
uint8_t led_state = OFF;
uint8_t port_state = OFF;
uint8_t prev_port_state = OFF;

ISR(PCINT2_vect) {
  takeButtonState();
  takeLedState();
  ((buttonPressed() == 1)) ? PORTB |= _BV(PB7) : (PORTB &= ~(_BV(PB7)));
}

ISR(USART0_UDRE_vect) {
  if (!bufferIsEmpty(&buffer))
    UDR0 = popFromBuff(&buffer);
  else 
    UCSR0B &= ~_BV(UDRIE0);
}

static void  init_port(void) {
  DDRB |= _BV(PB7);
  DDRK &= ~_BV(PK0);

  PORTB &= ~_BV(PB7);
  PORTK |= _BV(PK0);
}

static void init_interrupt(void) {
  PCICR |= _BV(PCIE2); 
  PCMSK2 |= _BV(PCINT16);
}

static void init_uart(void) {
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

int  main(void)
{
  cli();
  
  init_port();
  init_interrupt();
  init_uart();
  if (!init_buffer(&buffer, BUFF_SIZE))
    return (0);
  
  sei();
  
  u_print("Initialization is done ...\n");
  
  while (1) {

    if (!bufferIsEmpty(&buffer)) {
      UCSR0B |= _BV(UDRIE0);
    }
  }
  return (0);
}
