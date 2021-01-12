//
// Created by jestemleon on 08.01.2021.
//

#ifndef SHAREDMEMORY_HPP
#define SHAREDMEMORY_HPP

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <cstring>
#include <semaphore.h>
#include <chrono>

#define MAX_STATIONS 15

struct data {
    float coords[MAX_STATIONS][3];
    std::chrono::system_clock::time_point timestamp;
};

class SharedMemory {
public:
    SharedMemory(bool will_write, const char *shm_name, const char *sem_cons, const char *sem_prod);
    ~SharedMemory();

    data *sh_data;
    void push(data *buf);
    void pop(data *buf);
    int getSize() { return size; }

private:
    const char *shm_name;
    int shm_id;

    const char* sem_prod;
    const char* sem_cons;
    sem_t* producer;
    sem_t* consumer;

    int size;
};


#endif

