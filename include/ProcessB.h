//
// Created by jestemleon on 09.01.2021.
//

#ifndef SCZR_PROCESSB_H
#define SCZR_PROCESSB_H

#include "utilities.h"
#include "AbstractProcess.h"
#include "SharedMemory.h"
#include "SharedQueue.h"

class ProcessB : public AbstractProcess {
public:
    ProcessB() : shmBC(true, SHMEM_BC, BC_SEM_CONS, BC_SEM_PROD),
        queueA(false, false, MQUEUE_A),
        queueB(true, true, MQUEUE_B) {};

    [[noreturn]] void operate(int stations, int x, int y) override;
private:
    SharedMemory shmBC;
    SharedQueue queueA, queueB;
};


#endif //SCZR_PROCESSB_H
