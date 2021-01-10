#include <iostream>
#include <pthread.h>
#include <chrono>
#include <unistd.h>
#include <csignal>
#include <fstream>

#include "utilities.h"
#include "SharedMemory.h"
#include "SharedQueue.h"
#include "ProcessA.h"
#include "ProcessB.h"
#include "ProcessC.h"
using namespace std;

void *LoggingThread(void *n);

template <typename T>
pid_t startProcess();

int main(){


    sem_t *producerAB = sem_open(AB_SEM_PROD, O_CREAT, 0660, 1);
    sem_t *consumerAB = sem_open(AB_SEM_CONS, O_CREAT, 0660, 0);
    sem_t *producerBC = sem_open(BC_SEM_PROD, O_CREAT, 0660, 1);
    sem_t *consumerBC = sem_open(BC_SEM_CONS, O_CREAT, 0660, 0);
    mqd_t log_qB = mq_open(MQUEUE_B, O_CREAT | O_RDWR | O_NONBLOCK, 0660, nullptr);
    mqd_t log_qC = mq_open(MQUEUE_C, O_CREAT | O_RDWR | O_NONBLOCK, 0660, nullptr);

    pid_t procA, procB, procC;
    pthread_t loggerB, loggerC;
    int logger_idB, logger_idC;
    procA = startProcess<ProcessA>();   //generator
    procB = startProcess<ProcessB>();   //analyser
    procC = startProcess<ProcessC>();   //visualiser
    logger_idB = pthread_create(&loggerB, nullptr, LoggingThread, (void *) MQUEUE_B);
    logger_idC = pthread_create(&loggerC, nullptr, LoggingThread, (void *) MQUEUE_C);
    if(logger_idB) {
        cout << "Error: unable to create thread, " << logger_idB << endl;
        exit(-1);
    } else if(logger_idC) {
        cout << "Error: unable to create thread, " << logger_idC << endl;
        exit(-1);
    }

    char c = ' ';
    while(c != 'q') {
        cout << "Generator ID: " << procA << endl;
        cout << "Analyser ID: " << procB << endl;
        cout << "Visualiser ID: " << procC << endl;
        cout << "LoggerB results in: " << LOG_FILE_B << endl;
        cout << "LoggerC results in: " << LOG_FILE_C << endl;
        cout << "To end, enter q: ";
        cin >> c;
    }

    kill(procA, SIGTERM);
    kill(procB, SIGTERM);
    kill(procC, SIGTERM);

    shm_unlink(SHMEM_AB);
    shm_unlink(SHMEM_BC);
    mq_unlink(MQUEUE_B);
    mq_unlink(MQUEUE_C);
    sem_unlink(AB_SEM_CONS);
    sem_unlink(AB_SEM_PROD);
    sem_unlink(BC_SEM_PROD);
    sem_unlink(BC_SEM_PROD);

    return 0;
}

//universal logging thread for message queues
void *LoggingThread(void *threadargs = nullptr) {
    const char *logger_name;
    if(threadargs == nullptr || ((const char *)threadargs != MQUEUE_B && (const char *)threadargs != MQUEUE_C)) {
        cout << "Error: unable to recognize message queue name." << endl;
        exit(-1);
    }

    logger_name = (const char *)threadargs;
    SharedQueue logger(false, false, logger_name);
    ofstream output;
    (logger_name == MQUEUE_B) ? output.open(LOG_FILE_B) : output.open(LOG_FILE_C);

    log_message log;
    while(true) {
        auto *temp = &log;
        logger.pop(temp);

        if (temp && output.good()) {
            auto time = std::chrono::duration_cast<std::chrono::microseconds>(log.end - log.start).count();
            output << log.id << ": " << time << endl;
        }
    }
}

template <typename T>
pid_t startProcess() {
    pid_t result = fork();
    if (result == 0) {
        T process;
        process.operate();
        return 0;
    }
    else
        return result;
}
