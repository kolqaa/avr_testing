#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define OFF 0
#define ON 1
#define BAUDERATE 16000000L
volatile int led_state = OFF;
volatile int port_state = OFF;
volatile int prev_port_state = OFF;

static void takeButtonState(void) {
  if (!(PINK & (1 << PK0)))
    port_state = ON;
  else 
    port_state = OFF;
}

static void takeLedState(void) {
  if (!(PINB & (1 << PB7)))
    led_state = ON;
  else
    led_state = OFF;
}

static int butPres(void) {
  if (port_state == ON && prev_port_state == OFF)
    {
      if (led_state == ON)
	led_state = OFF;
      else
	led_state = ON;
    }
  prev_port_state = port_state;
  return (led_state == ON ? 1 : 0);
}

ISR(PCINT2_vect) {
  takeButtonState();
  takeLedState();
  ((butPres() == 1)) ? PORTB |= _BV(PB7) : (PORTB &= ~(_BV(PB7)));
}

static void  init_port(void){
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
  const long ubrr = F_CPU/8/BAUDERATE - 1;
  UBRR0H = ubrr >> 8;
  UBRR0L = ubrr & 0xff;
  UCSR0B = (0 << RXEN0) | (1 << TXEN0);
  UCSR0C = (0 << USBS0) | (3 << UCSZ00);
  UDR0 = 'd';
}

int  main(void)
{
  cli();
  init_port();
  init_interrupt();
  init_uart(); 
  sei();

  while (1) {
    
  }
}
