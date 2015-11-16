/*
 * main.cpp
 *
 *  Created on: Nov 6, 2015
 *      Author: root
 */

#include "avr/io.h"
#include "avr/interrupt.h"
#include "Uart.h"
#include "Buffer.h"


void delay(){
    volatile unsigned long x = 0xffff;
    while(x--);
}

int main() {
	Uart u;
	u.interrupton();
//	ringBufS_init(& u.rx);
//	ringBufS_init(& u.tx);
//	while(1){
//		ringBufS_put(& u.tx, 'J');
//		UDR0 = ringBufS_get(& u.tx);
//		delay();
//		ringBufS_put(& u.tx, 'A');
//		UDR0 = ringBufS_get(& u.tx);
//		delay();
//		ringBufS_put(& u.tx, 'C');
//		UDR0 = ringBufS_get(& u.tx);
//		delay();
//		ringBufS_put(& u.tx, 'K');
//		UDR0 = ringBufS_get(& u.tx);
//		delay();
//		ringBufS_put(& u.tx, 'E');
//		UDR0 = ringBufS_get(& u.tx);
//		delay();
//	}
	while (true) {
		PORTB |= _BV(PORTB5);
		UCSR0B |= 0x20;
		u.tx.circBufPush(& u.tx, u.rx.circBufPop(& u.rx));
	}

	return 0;
}

