//
// Created by jestemleon on 09.01.2021.
//

#ifndef SCZR_PROCESSA_H
#define SCZR_PROCESSA_H

#include "utilities.h"
#include "AbstractProcess.h"
#include "SharedMemory.h"

typedef void * (*THREADFUNCPTR)(void *);

class ProcessA : public AbstractProcess {
public:
    ProcessA() : shmAB(true, SHMEM_AB, AB_SEM_CONS, AB_SEM_PROD) {};

    //void *RunStation(void *threadarg);
    [[noreturn]] void operate() override;
private:
    SharedMemory shmAB;
};


#endif //SCZR_PROCESSA_H
