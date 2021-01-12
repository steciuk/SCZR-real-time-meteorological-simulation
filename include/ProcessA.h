//
// Created by jestemleon on 09.01.2021.
//

#ifndef SCZR_PROCESSA_H
#define SCZR_PROCESSA_H

#include "utilities.h"
#include "AbstractProcess.h"
#include "SharedQueue.h"

typedef void * (*THREADFUNCPTR)(void *);

class ProcessA : public AbstractProcess {
public:
    ProcessA() : queueA(true, false, MQUEUE_A) {};

    [[noreturn]] void operate(int stations) override;
private:
    SharedQueue queueA;
};


#endif //SCZR_PROCESSA_H
