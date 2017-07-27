#include "../headers/main.h"

void takeButtonState(void) {
  if (!(PINK & (1 << PK0)))
    g_port_state = ON;
  else
    g_port_state = OFF;
}

void takeLedState(void) {
  if (!(PINB & (1 << PB7)))
    g_led_state = ON;
  else
    g_led_state = OFF;
}


bool buttonPressed(void) {
  if (g_port_state == ON && g_prev_port_state == OFF)
    {
      u_print("Button was pressed. [Led status: ");
      if (g_led_state == ON)
	{
	  u_print("ON]\n");
	  g_led_state = OFF;

	}
      else {
	u_print("OFF]\n");
	g_led_state = ON;
      }
    }
  g_prev_port_state = g_port_state;
  return (g_led_state == ON ? 1 : 0);
}
