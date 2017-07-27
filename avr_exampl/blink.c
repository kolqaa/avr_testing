#include <avr/io.h>
#include <util/delay.h>

#deifne LED_PIN 1 << 7

int main(void)
{
  DDRB |= LED_PIN;
  
  while (1) {
    PORTB |= LED_PIN;
    delay(1000);
    PORTB &= ~LED_PIN;
    delay(1000);
  }
}
