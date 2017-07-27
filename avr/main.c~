#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned char g_state_pwm = 0;

void init_port(void) {
  DDRB |= _BV(PB7);
  PORTB |= _BV(PB7);
}

void set_pwm_timer(void) {
  TCCR0A = (_BV(COM1A1)) | (_BV(WGM11)) | (_BV(WGM10)); //set CTC, FAST PWM
  TCCR0B |=_BV(CS12); // prescaler 256
  OCR0A = 0x00; // start value 255;
}

void fade_up(void) {
  (OCR0A > 254) ? g_state_pwm = 1 : OCR0A++;
  _delay_ms(10);
}

void  fade_down(void) {
  (OCR0A < 1) ? g_state_pwm = 0 : OCR0A--;
  _delay_ms(10);
}
int main() {

  init_port();
  set_pwm_timer();
  sei();
  
  while (1) 
    (g_state_pwm == 0) ? fade_up() : fade_down();
  
  return 0;
}

