#include "tasks.h"

void main0() {
    while (1) {
        if (mtx_take(mutex)) {
            usartSendMessage("This is thread0\n\r");
            mtx_give(mutex);
        }

        thd_delay(threadManager->currentThread, 50);
    }
}

void main1() {
    while (1) {
        if (mtx_take(mutex)) {
            usartSendMessage("Thread1 here!\n\r");
            mtx_give(mutex);
        }

        thd_delay(threadManager->currentThread, 50);
    }
}

void main2() {
    while (1) {
        if (mtx_take(mutex)) {
            usartSendMessage("How about thread2?\n\r");
            mtx_give(mutex);
        }

        thd_delay(threadManager->currentThread, 100);
    }
}

void idleTask() {
    while (1) {
    }
}