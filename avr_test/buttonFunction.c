#include "main.h"

void takeButtonState(void) {
  if (!(PINK & (1 << PK0)))
    port_state = ON;
  else
    port_state = OFF;
}

void takeLedState(void) {
  if (!(PINB & (1 << PB7)))
    led_state = ON;
  else
    led_state = OFF;
}


bool buttonPressed(void) {
  if (port_state == ON && prev_port_state == OFF)
    {
      u_print("Button was pressed\n");
      if (led_state == ON)
	led_state = OFF;
      else
	led_state = ON;
    }
  prev_port_state = port_state;
  return (led_state == ON ? 1 : 0);
}
