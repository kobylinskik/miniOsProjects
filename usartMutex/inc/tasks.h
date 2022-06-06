#ifndef __TASKS__
#define __TASKS__

#include "circularBuffer.h"
#include "mutex.h"
#include "threadManager.h"
#include "usartDriver.h"

CircularBuffer_t * buffer;
mutex_t * mutex;

void main0();
void main1();
void main2();
void idleTask();

#endif