/*
 * Uart.cpp
 *
 *  Created on: 13 de nov de 2015
 *      Author: aluno
 */

#include "Uart.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "Buffer.h"

Uart Uart::u;
Buffer Uart::rx;
Buffer Uart::tx;


Uart::Uart(){
	//SERIAL
	UBRR0H = 0;
	UBRR0L = 103;
	UCSR0C = 0x06;
	UCSR0B = 0x98;
	//LED
	PINB = 0x23;
	DDRB = 0x24;
	PORTB = 0x80;
}

void Uart::rx_interrupt_handler() {
	if(u.rx.circBufPush(& u.rx,UDR0) == -1) PORTB |= _BV(PORTB5);
	//TEST
//	PORTB &= ~_BV(PORTB5);	//LIGA LED
//	PORTB |= _BV(PORTB5);	//DESLIGA LED
}

void Uart::empty_interrupt_handler(){
	//TEST
//	PORTB &= ~_BV(PORTB5);	//LIGA LED
//	PORTB |= _BV(PORTB5);	//DESLIGA LED
	uint8_t aux = u.tx.circBufPop(& u.tx);
	if(aux == -1) PORTB |= _BV(PORTB5);
	UDR0 = aux;
	UCSR0B &= ~0x20;
}

ISR(USART_RX_vect ){
	Uart::rx_interrupt_handler();
}

ISR(USART_UDRE_vect ){
	Uart::empty_interrupt_handler();
}

void Uart::interrupton(){
	sei();
}

void Uart::interruptoff(){
	cli();
}
