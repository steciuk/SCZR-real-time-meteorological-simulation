#include "SharedMemory.hpp"

SharedMemory::SharedMemory(bool will_write, char *shm_name, char *sem_cons, char *sem_prod) {
    size = sizeof(data);
    shm_id = shm_open(shm_name, O_CREAT | O_RDWR, 0660);
    this->shm_name = shm_name;

    ftruncate(shm_id, size);

    sh_data = will_write ? (data*)mmap(nullptr, size, PROT_WRITE, MAP_SHARED, shm_id, 0)
            : (data*)mmap(nullptr, size, PROT_READ, MAP_SHARED, shm_id, 0);

    int errorno = 0;
    if((producer = sem_open(sem_prod, 0)) == SEM_FAILED){
        printf("%S", strerror(errorno));
    }
    if((consumer = sem_open(sem_cons, 0)) == SEM_FAILED) {
        printf("%S", strerror(errorno));
    };

    if(errorno != 0) {
        exit(3);
    }

    this->sem_cons = sem_cons;
    this->sem_prod = sem_prod;
}

SharedMemory::~SharedMemory() {
    shm_unlink(shm_name);
    sem_unlink(sem_cons);
    sem_unlink(sem_prod);
}

void SharedMemory::push(unsigned char* buf) {
    sem_wait(producer);

    sem_post(consumer);
}


void SharedMemory::pop(unsigned char *buf) {
    sem_wait(consumer);

    sem_post(producer);
}