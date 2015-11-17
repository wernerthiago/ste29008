/*
 * Buffer.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: root
 */

#include "Buffer.h"
#include "avr/io.h"
#include "stdlib.h"

//#define MAX_SIZE 256

Buffer Buffer::b;
uint8_t * const Buffer::buffer[MAX_SIZE] = {0};
const int Buffer::maxLen = MAX_SIZE;

void operator delete(void* p) {
	free(p);
}

Buffer::Buffer() {
	// TODO Auto-generated constructor stub
}

Buffer::~Buffer() {
	// TODO Auto-generated destructor stub
}

uint8_t Buffer::circBufPop(Buffer * c){
	if (c->getHead() == c->getTail())
		return -1;
	uint8_t * aux = c->getBuffer();
	uint8_t data = aux[c->getTail()];

	int next = c->getTail() + 1;
	if(next >= c->getMaxLen())
		next = 0;

	c->setTail(next);

	return data;
}

int Buffer::circBufPush(Buffer *c, uint8_t data){
	int next = c->getHead() + 1;

	if (next >= c->getMaxLen()){
		next = 0;
	}

	if (next == c->getTail())
		return -1;
	uint8_t * aux = c->getBuffer();
	aux[c->getHead()] = data;
	c->setHead(next);
	return 0;
}
