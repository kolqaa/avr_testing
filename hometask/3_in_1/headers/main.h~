#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

#define OFF 0
#define ON 1
#define BAUDERATE 115200
#define BUFF_SIZE 256
#define BUFF_MASK (BUFF_SIZE - 1)

extern uint8_t g_led_state;
extern uint8_t g_port_state;
extern uint8_t g_prev_port_state;
extern unsigned char g_timer;
extern unsigned char g_step_brightness;

typedef struct buffer {
  char		*array;
  uint16_t	size;
  uint8_t	read;
  uint8_t	write;
}              buffer_t;

/*
 * Ring buffer function
 */

uint8_t		init_buffer(buffer_t *buffer, uint16_t size);
uint8_t		bufferIsFull(buffer_t *buffer);
uint8_t		bufferIsEmpty(buffer_t *buffer);
void		pushInBuff(buffer_t *buffer, char data);
char		popFromBuff(buffer_t *buffer);

/*
 * Switch Led ON/OFF Function 
 */

void		takeButtonState(void);
void		takeLedState(void);
bool		buttonPressed(void);

/*
 * UART print 
 */

void		u_print(char *str);
void		u_printnumbers(long nb);
void		u_printchar(char c);

/*
 * Encoder function for dimming led
 */

void		fade_up(void);
void		fade_down(void);

#endif
