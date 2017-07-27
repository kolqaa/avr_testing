#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdint.h>

#define TURN_ON_OUTPUT 1 << 7
#define TURN_ON_INPUT 0 << 0
#define LED_ON 1 << 7
#define LED_OFF ~(1 << 7)
#define MAX_BRIGHTNESS 170


int main(void) {

  unsigned int button_timer = 0;
  
  DDRB |= (TURN_ON_OUTPUT);
  DDRL &= ~(TURN_ON_INPUT);

  PORTB &= ~(1 << 7);
  PORTL |= (1 << 0); 
  
  while (1) {

    if (!(PINL & (1 << 0)))
      {

	if (button_timer < 5)
	  button_timer++;
	else
	  PORTB = 0b10000000;
      }
      else
	{
	  if (button_timer > 0)
	    button_timer--;
	  else
	    PORTB = 0b00000000;
	}
  }

  return (0);    
}
  
