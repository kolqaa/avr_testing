#include "../headers/main.h"

void	fade_up(void) {
  if (OCR0A == 240){
    OCR0A = 240;
    u_print("Led brightness on MAX value, turn encoder to the left, to make it darker\n");
  }
  else {
    OCR0A += g_step_brightness;
    u_print("Brightness up [Rotate direction: Right");
    u_print(", value: ");
    u_printnumbers(OCR0A);
   u_print("%]\n");
  }
}

void	fade_down(void) {
  if (OCR0A == 0) {
    u_print("Led brightness on LOW value, turn encoder to the right, to make it brighter\n");
    OCR0A = 0;
  }
  else {
    u_print("Brightness down [Rotate direction: Left");
    u_print(", value: ");
    u_printnumbers(OCR0A);
    u_print("%]\n");
    
    OCR0A -= g_step_brightness;
  }
}

