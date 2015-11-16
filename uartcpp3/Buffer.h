/*
 * Buffer.h
 *
 *  Created on: Nov 14, 2015
 *      Author: root
 */

#ifndef BUFFER_H_
#define BUFFER_H_
#include "avr/io.h"
#define MAX_SIZE 32

class Buffer {
public:
	Buffer();
	virtual ~Buffer();
	int circBufPush(Buffer * c, uint8_t data);
	uint8_t circBufPop(Buffer * c);

	uint8_t * const getBuffer() const {
		return * buffer;
	}

	int getHead() const {
		return head;
	}

	void setHead(int head) {
		this->head = head;
	}

	const int getMaxLen() const {
		return maxLen;
	}

	int getTail() const {
		return tail;
	}

	void setTail(int tail) {
		this->tail = tail;
	}

private:
	static Buffer b;
    static uint8_t * const buffer[MAX_SIZE];
    int head;
    int tail;
    static const int maxLen;
};

#endif /* BUFFER_H_ */
