//
// Created by jestemleon on 09.01.2021.
//

#include "ProcessB.h"
#include <cstdlib>
#include <unistd.h>

[[noreturn]] void ProcessB::operate() {
    data fromA{}, toC{};
    log_message log{};

    while(true) {
        shmAB.pop(&fromA);
        auto halfway = std::chrono::system_clock::now();

        log.id = fromA.temp;
        log.start = fromA.timestamp;
        log.end = halfway;
        queueB.push(&log);

        toC.temp = fromA.temp / 3;
        toC.timestamp = std::chrono::system_clock::now();
        shmBC.push(&toC);
    }
}