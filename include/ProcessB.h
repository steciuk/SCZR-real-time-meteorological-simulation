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
    ProcessB() : shmAB(false, SHMEM_AB, AB_SEM_CONS, AB_SEM_PROD),
        shmBC(true, SHMEM_BC, BC_SEM_CONS, BC_SEM_PROD),
        queueB(true, true, MQUEUE_B) {};

    [[noreturn]] void operate() override;
private:
    SharedMemory shmAB, shmBC;
    SharedQueue queueB;
};


#endif //SCZR_PROCESSB_H
