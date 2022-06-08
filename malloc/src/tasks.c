#include "tasks.h"

void main0() {
    while (1) {
        usartSendNumber(memMang_getTotalRemainingHeapSpace());
        usartSendMessage("\n\r");
        thdMang_addThread(threadManager, &main1);

        thdMang_deleteCurrentThread(threadManager);
    }
}

void main1() {
    while (1) {
        usartSendNumber(memMang_getTotalRemainingHeapSpace());
        usartSendMessage("\n\r");
        thdMang_addThread(threadManager, &main0);

        thdMang_deleteCurrentThread(threadManager);
    }
}

void main2() {
    while (1) {
        /*if (mtx_take(mutex)) {
            usartSendMessage("How about thread2?\n\r");
            mtx_give(mutex);
        }

        thd_delay(threadManager->currentThread, 100);*/
    }
}

void idleTask() {
    while (1) {
    }
}

void heapFaultHandler(void) {
    usartSendMessage("Not enough heap space!\n\r");
}