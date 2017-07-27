#include "headers/main.h"
#include <util/delay.h>

buffer_t buffer;
uint8_t g_led_state = OFF; /*current led state flag*/
uint8_t g_port_state = OFF; /*current port state flag for button*/
uint8_t g_prev_port_state = OFF; /*previous port state for button */
unsigned char g_timer = OFF; /*flag for pwm_timer on/off */
unsigned char g_step_brightness = 2; 




void	u_printnumbers(long nb)
{
  if (nb < 0)
    {
      u_printchar('-');
      nb = -nb;
    }
  if (nb >= 10)
    {
      u_printnumbers(nb / 10);
      u_printnumbers(nb % 10);
    }
  else
    {
      u_printchar(nb + '0');
    }
}

static void pwm_timer_on(void) {
  TCCR0A = (_BV(COM1A1)) | (_BV(WGM11)) | (_BV(WGM10));
  TCCR0B |=_BV(CS12);
  TCNT0 = 0x00;
  TIMSK0 = 0x00;
  OCR0A = 0x00;
}

ISR(INT5_vect)
{
  if (g_timer == OFF) {
    pwm_timer_on();
    g_timer = ON;
  }
  if(!(PINH & (1<<PH4)) == 0)
      fade_up();
  else
      fade_down();
}

static void pwm_timer_off(void) {
  TCCR0A = 0;
  TCCR0B = 0;
}

ISR(PCINT2_vect) {
  pwm_timer_off();
  g_timer = OFF;
  takeButtonState();
  takeLedState();
  ((buttonPressed() == 1)) ? PORTB |= _BV(PB7) : (PORTB &= ~(_BV(PB7)));
}

ISR(USART0_UDRE_vect) {
  if (!bufferIsEmpty(&buffer))
    UDR0 = popFromBuff(&buffer);
  else 
    UCSR0B &= ~_BV(UDRIE0);
}

static void  init_port(void) {
  DDRB |= _BV(PB7);
  /*Port for encoder */
  DDRE |= _BV(PE5); 
  DDRH |= _BV(PH4);
  /*Port for button */
  DDRK &= ~_BV(PK0);

  PORTH |= _BV(PH4);
  PORTE |= _BV(PE5);
  PORTB &= ~_BV(PB7);
  PORTK |= _BV(PK0);
}

static void init_interrupt(void) {
  PCICR |= _BV(PCIE2);  /*For button interrupt*/
  PCMSK2 |= _BV(PCINT16);
  
  EICRB = (_BV(ISC51)) | (_BV(ISC50)); /*For encoder Interrupt*/
  EIMSK |= _BV(INT5);
}

static void init_uart(void) {
  UBRR0H = 0;            
  UBRR0L = 8;                 
  UCSR0B &= ~_BV(UCSZ02);              
  UCSR0C |= _BV(UCSZ01) | _BV(UCSZ00); 
  UCSR0C &= ~_BV(USBS0) & ~_BV(UPM00) & ~_BV(UPM01);   
  UCSR0B |= _BV(TXEN0);
}


void  u_print(char *str) {
  size_t i;
  for (i = 0 ; str[i]; i++) {
      if (!bufferIsFull(&buffer))
	pushInBuff(&buffer, str[i]);
    }
}

void u_printchar(char c) {
  if (!bufferIsFull(&buffer))
    pushInBuff(&buffer, c);
}

int  main(void)
{

  int num = 32200;
  cli();
  
  init_port();
  init_interrupt();
  init_uart();
  if (!init_buffer(&buffer, BUFF_SIZE)) 
    return (0);

  sei();

  u_printnumbers(num);
  u_print("\n");
  
  u_print("Initialization is done ...\n");
  
  while (1) {
    if (!bufferIsEmpty(&buffer))
      UCSR0B |= _BV(UDRIE0);   
  }
  
  return (0);
}
