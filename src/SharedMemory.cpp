//
// Created by jestemleon on 08.01.2021.
//

#include "SharedMemory.h"

SharedMemory::SharedMemory(bool will_write, const char *shm_name, const char *sem_cons, const char *sem_prod) {
    size = sizeof(data);
    shm_id = shm_open(shm_name, O_CREAT | O_RDWR, 0660);
    this->shm_name = shm_name;

    ftruncate(shm_id, getSize());

    sh_data = will_write ? (data*)mmap(nullptr, size, PROT_WRITE, MAP_SHARED, shm_id, 0)
            : (data*)mmap(nullptr, size, PROT_READ, MAP_SHARED, shm_id, 0);

    int errorno = 0;
    if((producer = sem_open(sem_prod, 0)) == SEM_FAILED){
        printf("%S", strerror(errorno));
    }
    if((consumer = sem_open(sem_cons, 0)) == SEM_FAILED) {
        printf("%S", strerror(errorno));
    };
    this->sem_cons = sem_cons;
    this->sem_prod = sem_prod;
}

SharedMemory::~SharedMemory() {
    shm_unlink(shm_name);
    sem_unlink(sem_cons);
    sem_unlink(sem_prod);
}

void SharedMemory::push(data *buf) {
    sem_wait(this->producer);
    memcpy(sh_data, buf, sizeof(data));
    sem_post(this->consumer);
}

void SharedMemory::pop(data *buf) {
    sem_wait(this->consumer);
    memcpy(buf, sh_data, sizeof(data));
    sem_post(this->producer);
}