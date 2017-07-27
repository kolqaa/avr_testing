#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned int compare_time = 0;
volatile unsigned char g_state_pwm = 0;

static void set_pwm_timer(void) {
  TCCR0A = (_BV(COM1A1)) | (_BV(WGM11)) | (_BV(WGM10));
  TCCR0B |=_BV(CS12);
   OCR0A = 0x00;
}

static void fade_up(void) {
  (OCR0A > 254) ? g_state_pwm = 1 : OCR0A++;
  _delay_ms(10);
}

static void  fade_down(void) {
  (OCR0A < 1) ? g_state_pwm = 0 : OCR0A--;
  _delay_ms(10);
}

ISR(PCINT0_vect) {
  if (!(PINB & (1 << PB5) && (!(PINB & (0 << PB4)))))
    fade_up();
  else if (!(PINB & (1 << PB4) && (!(PINB & (0 << PB5)))))
    fade_down();
}

static void	init_port(void) {
  DDRB |= _BV(PB7);
  DDRB = ~_BV(PB5) | ~_BV(PB4);  
  PORTB = _BV(PB5) | _BV(PB4);
  PORTB &= ~(_BV(PB7));
}

static void	init_interrupt(void) {
  PCICR |= _BV(PCIE0);
  PCMSK0 |= _BV(PCINT5);
  PCMSK0 |= _BV(PCINT4);
}

int main (void)
{
  cli();

  init_port();
  init_interrupt();
  set_pwm_timer();
  
  sei();
  while (1) {
    
  }
  return (0);

}
