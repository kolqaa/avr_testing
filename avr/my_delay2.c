#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

volatile unsigned int compare_time = 0;

void init_port(void) {
  DDRB |= _BV(PB7);//LED_BIT;
  PORTB &= ~_BV(PB7);//LED_BIT;
}

ISR(TIMER1_OVF_vect) {
  compare_time++; 
}

void my_delay_ms(unsigned int timer) {
  while(compare_time < timer)
    ;
  compare_time = 0;
}

void set_timer(void) {
  TCNT1 = 0x7D0;
  TCCR1B = (_BV(CS12)) | (_BV(CS10));
  TIMSK1 |= _BV(TOIE1); //set interrupt reaction on CTC mode
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

