//
// Created by jestemleon on 10.01.2021.
//

#ifndef SCZR_PROCESSC_H
#define SCZR_PROCESSC_H

#include "utilities.h"
#include "AbstractProcess.h"
#include "SharedMemory.h"
#include "SharedQueue.h"

class ProcessC : public AbstractProcess {
public:
    ProcessC() : shmBC(false, SHMEM_BC, BC_SEM_CONS, BC_SEM_PROD),
        queueC(true, true, MQUEUE_C) {};

    [[noreturn]] void operate() override;
private:
    SharedMemory shmBC;
    SharedQueue queueC;
};

#endif //SCZR_PROCESSC_H
