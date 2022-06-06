#include "circularBuffer.h"
#include "hwConfig.h"
#include "sysTickHandler.h"
#include "sysTickSetup.h"
#include "tasks.h"
#include "threadManager.h"

int main() {
    setupClocks();
    setupUartPins();
    setupUsart2();

    memMang_initHeap();

    threadManager = thdMang_createThreadManager(&idleTask);

    thdMang_addThread(threadManager, &main0);
    thdMang_addThread(threadManager, &main1);
    thdMang_addThread(threadManager, &main2);

    mutex = mtx_createMutex();

    setupSystick();

    thdMang_start(threadManager);

    while (1) {
    }
}