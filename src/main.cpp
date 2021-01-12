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
pid_t startProcess(int s, int x, int y);

int main() {
    pid_t procA, procB, procC;
    pthread_t loggerB, loggerC;
    int logger_idB, logger_idC;
    int stations, x, y;

    char option, aff = ' ';
    cout << "Choose scheduling policy and visualiser process affinity first:\n";
    cout << "SCHEDULING POLICY:\n 1 - FIFO   2 - RR (RoundRobin)\n Other value - Default\n";
    cout << "Choose option: ";
    cin >> option;
    if(option == '1' || option == '2') {
        cout << "Should visualiser be bound to cpu core? [Y/N]: ";
        cin >> aff;
    }
    cout << "What size should the map be? It will determine the number of possible stations.\n"
            "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;

    cout << "How many stations should be visualised?\n"
            "Between 1 - 200, not bigger than " << x * y << ": ";
    cin >> stations;
    if(stations < 1 || stations > 200 || stations > x * y) {
        cout << "Incorrect amount. Please write correct number: ";
        cin >> stations;
    }

    sem_t *producerBC = sem_open(BC_SEM_PROD, O_CREAT, 0660, 1);
    sem_t *consumerBC = sem_open(BC_SEM_CONS, O_CREAT, 0660, 0);
    mqd_t data_qA = mq_open(MQUEUE_A, O_CREAT | O_RDWR | O_NONBLOCK, 0660, nullptr);
    mqd_t log_qB = mq_open(MQUEUE_B, O_CREAT | O_RDWR | O_NONBLOCK, 0660, nullptr);
    mqd_t log_qC = mq_open(MQUEUE_C, O_CREAT | O_RDWR | O_NONBLOCK, 0660, nullptr);

    procA = startProcess<ProcessA>(stations, x, y);   //generator
    procB = startProcess<ProcessB>(stations, x, y);   //buffer
    procC = startProcess<ProcessC>(stations, x, y);   //visualiser
    logger_idB = pthread_create(&loggerB, nullptr, LoggingThread, (void *) MQUEUE_B);
    logger_idC = pthread_create(&loggerC, nullptr, LoggingThread, (void *) MQUEUE_C);
    if(logger_idB) {
        cout << "Error: unable to create thread, " << logger_idB << endl;
        exit(-1);
    } else if(logger_idC) {
        cout << "Error: unable to create thread, " << logger_idC << endl;
        exit(-1);
    }

    sched_param ps{99};
    int result = 0;
    switch(option) {
        case '1':
            result |= sched_setscheduler(procA, SCHED_FIFO, &ps);
            result |= sched_setscheduler(procB, SCHED_FIFO, &ps);
            result |= sched_setscheduler(procC, SCHED_FIFO, &ps);
            break;
        case '2':
            result |= sched_setscheduler(procA, SCHED_RR, &ps);
            result |= sched_setscheduler(procB, SCHED_RR, &ps);
            result |= sched_setscheduler(procC, SCHED_RR, &ps);
            break;
        default:
            break;
    }
    if(result) {
        cout << "Error: unable to change scheduling policy.\n" << strerror(errno) << endl;
        exit(-1);
    }

    if(aff == 'Y' || aff == 'y') {
        cpu_set_t cpuSet;
        CPU_ZERO(&cpuSet);
        CPU_SET(3, &cpuSet);
        result |= sched_setaffinity(procC, sizeof(cpu_set_t), &cpuSet);

        if(result) {
            cout << "Error: unable to change affinity.\n" << strerror(errno) << endl;
            exit(-1);
        }
    }

    char c = ' ';
    while(c != 'q') {
        cout << "Generator ID: " << procA << endl;
        cout << "Buffer ID: " << procB << endl;
        cout << "Visualiser ID: " << procC << endl;
        cout << "LoggerB results in: " << LOG_FILE_B << endl;
        cout << "LoggerC results in: " << LOG_FILE_C << endl;
        cout << "To end, enter q: ";
        cin >> c;
    }

    kill(procA, SIGTERM);
    kill(procB, SIGTERM);
    kill(procC, SIGTERM);

    shm_unlink(SHMEM_BC);
    mq_unlink(MQUEUE_A);
    mq_unlink(MQUEUE_B);
    mq_unlink(MQUEUE_C);
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
            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(log.end - log.start).count();
            output <<"Station ID: " << log.id  << " Temp: " << log.temp << " time: " << time << endl;
        }
    }
}

template <typename T>
pid_t startProcess(int s, int x, int y) {
    pid_t result = fork();
    if (result == 0) {
        T process;
        process.operate(s, x, y);
        return 0;
    }
    else
        return result;
}
