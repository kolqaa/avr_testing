#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define TURN_ON_OUTPUT 1 << 7
#define LED_ON 1 << 7
#define LED_OFF ~(1 << 7)
#define MAX_BRIGHTNESS 170

void my_delay (unsigned int time) {
  
 unsigned int c, d;
  
  for ( c = 0 ; c <= time ; c++ )
    for ( d = 0 ; d <= time ; d++ );
}


int main() {

  DDRB |= TURN_ON_OUTPUT;

  int timer = 5;
  int blackout = 0;

  while (timer != MAX_BRIGHTNESS) {
      PORTB |= LED_ON;
      my_delay(timer);
      PORTB &= LED_OFF;
      my_delay(170);
      timer++;
      if (timer >= MAX_BRIGHTNESS)
	blackout = 1;
      
      while (blackout) {
	  PORTB |= LED_ON;
	  my_delay(timer);
	  PORTB &= LED_OFF;
	  my_delay(170);
	  timer--;
	  if (timer == 0)
	    blackout = 0;
	}
  }
  return (0);    
}
  
