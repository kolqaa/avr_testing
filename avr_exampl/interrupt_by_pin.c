#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>

#deinfe LED_PIN PB7 
#deinfe INTERRUPT_PIN PB4


ISR(PCINT0_vect) {
  PORTB &= ~_BV(LED_PIN); //turn off led
}

void init_port(void)
{
  DDRB |= _BV(LED_PIN); // init LED PIN to output
  DDRB &= ~_BV(INTERRUPT_PIN); // init pin (10) to input
  PORTB |= _BV(INTERRUPT_PIN); //inti pull-up to pin 10 
}

void init_interrupt(void)
{
  cli(); //clear SEG bit;
  PCICR |= (1<<PCIE0); //set MASK
  PCMSK0 |= (1<<PCINT4); //set PIN 10 (PCINT4);
  sei(); //accept global interrups 
}


int main(void) {

  init_port();
  init_interrupt();

  while (1) {
    //blinking our led till inerrupt
     PORTB |= _BV(LED_PIN);
    _delay_ms(500);
    PORTB &= ~_BV(LED_PIN);
    _delay_ms(500);
  }

  return (0);
}
