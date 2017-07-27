#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

volatile unsigned int compare_time = 0;

void init_port(void) {
  DDRB |= _BV(PB7);//LED_BIT;
  PORTB &= ~_BV(PB7);//LED_BIT;
}

ISR(TIMER2_OVF_vect) {
  compare_time++; 
}

void my_delay_ms(unsigned int timer) {
  while(compare_time < timer)
    ;
  compare_time = 0;
  TCNT2 = 130; //update Timer Count;
  TIFR2 = 0x00; //clear overflow interrupt flag;
}

void set_timer(void) {
  TCCR2B = 0x00; // Disable timer2 while we set up it
  TCNT2 = 130; /* The timer overflow interrupt fires every 1ms by setting the prescaler to 128 and preloading Timer2's counter with 130.
		*Timer2 is 8-bits so the max number it can count to is 255, 
		*this leaves 125 cycles left to count. The Arduino has a clock of 16MHz so:
		*(1/16E6) * 125 * prescalaer = 1ms
		*/
  TIFR2 = 0x00; // Clear timer overflow flag
  TIMSK2 = 0x01; //Timer2 overflow interrupt enable 
  TCCR2A = 0x00; // Wave gen mode
  TCCR2B = 0xA4; // set prescaler to 164 (With that value it has better result)
}

int main() {

  init_port();
  set_timer();
  
  sei();

  while(1) {
    PORTB &= ~_BV(PB7); 
    my_delay_ms(1000);
    PORTB |= _BV(PB7);
    my_delay_ms(1000);
  }
  return 0;
}

