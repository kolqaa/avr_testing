#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

volatile unsigned int compare_time = 0;

void init_port(void) {
  DDRB |= _BV(PB7);//LED_BIT;
  PORTB &= ~_BV(PB7);//LED_BIT;
}

ISR(TIMER1_COMPA_vect) {
  compare_time++; 
}

void my_delay_ms(unsigned int timer) {
  while(compare_time < timer)
    ;
  compare_time = 0;
}

void set_timer(void) {
  TCCR1B = (_BV(WGM12)) | (_BV(CS11)); // set Prescaler 8, and CTC mode;
  TIMSK1 |= _BV(OCIE1A); //set interrupt reaction on CTC mode
  OCR1A = 0x7D0; //set value to compare 
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

