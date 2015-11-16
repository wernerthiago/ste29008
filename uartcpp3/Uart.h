/*
 * Uart.h
 *
 *  Created on: 13 de nov de 2015
 *      Author: aluno
 */

#ifndef UART_H_
#define UART_H_

#include "Buffer.h"

class Uart {
private:
	static Uart u;

public:
	Uart();
	int uart_has_data();
	int uart_to_receive();
	static void rx_interrupt_handler();
	static void empty_interrupt_handler();
	static void interruptoff();
	static void interrupton();
	Buffer rx;
	Buffer tx;
};

#endif /* UART_H_ */
