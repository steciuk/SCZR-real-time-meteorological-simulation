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

struct data {
    int id{};
    int val{};
    std::chrono::system_clock::time_point timestamp{};
};

class SharedMemory {
public:
    SharedMemory(bool will_write, char *shm_name, char *sem_cons, char *sem_prod);
    ~SharedMemory();

    data *sh_data;
    void push(unsigned char *buf);
    void pop(unsigned char *buf);
    int getSize() { return size; }

private:
    char *shm_name;
    int shm_id{};

    char* sem_prod;
    char* sem_cons;
    sem_t* producer;
    sem_t* consumer;

    int size;
};


#endif

