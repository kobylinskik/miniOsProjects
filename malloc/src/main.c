#include "circularBuffer.h"
#include "hwConfig.h"
#include "memory.h"
#include "sysTickHandler.h"
#include "sysTickSetup.h"
#include "tasks.h"
#include "threadManager.h"

int main() {
    setupClocks();
    setupUartPins();
    setupUsart2();

    memMang_initHeap();
    usartSendNumber(memMang_getTotalRemainingHeapSpace());
    usartSendMessage("\n\r");

    memMang_heapFaultHandler = &heapFaultHandler;

    threadManager = thdMang_createThreadManager(&idleTask);
    usartSendNumber(memMang_getTotalRemainingHeapSpace());
    usartSendMessage("\n\r");

    thdMang_addThread(threadManager, &main0);

    usartSendNumber(memMang_getTotalRemainingHeapSpace());
    usartSendMessage("\n\r");

    mutex = mtx_createMutex();

    setupSystick();

    thdMang_start(threadManager);

    while (1) {
    }
}