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

void appSend(Uart u, uint8_t data){
	UDR0 = data;
	u.tx.circBufPush(& u.tx, UDR0);
}

uint8_t appReceive(Uart u){
	uint8_t data = u.rx.circBufPop(& u.tx);
}

int main() {
	Uart u;
	u.interrupton();

//	appSend(u,'x');
//	UDR0 = appReceive(u);
//	appSend(u,'z');
//	UDR0 = appReceive(u);
//	appSend(u,'w');
//	UDR0 = appReceive(u);
//	appSend(u,'t');
//	UDR0 = appReceive(u);

	while (true) {
		if(u.rx.getTail() != u.rx.getHead()){
			UCSR0B |= 0x20;
			u.tx.circBufPush(& u.tx, u.rx.circBufPop(& u.rx));
		}
	}
	return 0;
}

