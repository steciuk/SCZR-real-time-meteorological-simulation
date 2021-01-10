//
// Created by jestemleon on 08.01.2021.
//

#ifndef SHAREDQUEUE_HPP
#define SHAREDQUEUE_HPP

#include <mqueue.h>
#include <chrono>
#include <cstring>

//https://www.softprayog.in/programming/interprocess-communication-using-posix-message-queues-in-linux?PageSpeed=noscript

struct station_message {
    int x, y;
    int val;
    std::chrono::system_clock::time_point timestamp;
};

struct log_message {
    int id;
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
};

class SharedQueue {
public:
    explicit SharedQueue(bool will_write, bool non_block, const char* queue_name);
    ~SharedQueue() { mq_close(mq); }

    template <typename T>
    void push(T* msg_struct) {
        mq_send(mq, (const char *) msg_struct, sizeof(T), 0);
    }

    template <typename T>
    void pop(T*& msg_struct) {
        char buf[msg_size];
        auto result = mq_receive(this->mq, &buf[0], msg_size, 0);

        if(result != -1) {
            memcpy(msg_struct, buf, sizeof(T));
        }
        else {
            msg_struct = nullptr;
        }
    }

private:
    mqd_t mq;           //queue descriptor
    size_t msg_size;    //max size of msg
};

#endif