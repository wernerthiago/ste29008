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


Uart::Uart(){
	//SERIAL
	UBRR0H = 0;
	UBRR0L = 103;
	UCSR0C = 0x06;
	UCSR0B = 0x98;
	DDRB = 0x03;
	//LED
	PINB = 0x23;
	DDRB = 0x24;
	PORTB = 0x80;
	//BUFFER
	rx = new Buffer();
	tx = new Buffer();
}

void Uart::rx_interrupt_handler() {
	uint8_t aux = UDR0;
	rx.circBufPush(& rx,aux);
	//push

	//TEST
//	PORTB |= _BV(PORTB5);
}

void Uart::empty_interrupt_handler(){
	UCSR0B &= ~0x20;
//	PORTB &= ~_BV(PORTB5);
//	if(ringBufS_empty(& u.tx) > 0){
		uint8_t aux = u.tx.circBufPop(& u.tx);
		UDR0 = aux;
//	}
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
