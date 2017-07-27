#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define LED_PIN PB7
#define BUTTON_PIN PB6

void port_init() {
  DDRB |= _BV(LED_PIN);
  DDRB &= ~_BV(BUTTON_PIN);
  
  PORTB |= _BV(BUTTON_PIN);
  PORTB &= ~_BV(LED_PIN);
}

int main(void) {

  port_init();
  
  while (1) {
    (!(PINB & (1 << BUTTON_PIN))) ? (PORTB |= _BV(LED_PIN)) : (PORTB &= ~_BV(LED_PIN));
  }
  return (0);
}
