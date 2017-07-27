#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define TURN_ON_OUTPUT 1 << 7
#define LED_ON 1 << 7
#define LED_OFF ~(1 << 7)
#define MAX_BRIGHTNESS 170

ISR(PCINT0_vect) {
  PORTB |= LED_ON;
  _delay_ms(2000);
  PORTB &= ~(LED_OFF);
}

int main(void) {

  DDRB |= TURN_ON_OUTPUT;
  DDRK |= 0b00000000;

  PORTK |= 1 << 0;
  
  PCICR = (1<<PCEI0); 
  PCMSK0 = (1<<PCINT0);

  while (1) {
    
  }

  return (0);    
}
  
