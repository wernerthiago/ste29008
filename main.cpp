/*
 * main.cpp
 *
 *  Created on: Nov 6, 2015
 *      Author: root
 */

#include "avr/io.h"
#include "avr/interrupt.h"
#include <stdlib.h>
#include "Circular_Buffer.h"
#include "Uart.h"
#include "util/atomic.h"
#include "util/delay.h"
#define TIME 1		//milissegundos


void operator delete(void * p) {
	free(p);
}

int main() {
	Uart u;							//UART object
	u.interrupton();				//activate interrupts

	while (true) {
		if(u.has_data()){			//check UART for send data
			uint8_t aux = u.get();	//getting data
			_delay_ms(TIME);		//simulating data processing
			u.put(aux);				//transferring data
		}
	}
	return 0;
}

