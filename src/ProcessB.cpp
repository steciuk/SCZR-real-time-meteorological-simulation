//
// Created by jestemleon on 09.01.2021.
//

#include "ProcessB.h"
#include <cstdlib>
#include <unistd.h>

[[noreturn]] void ProcessB::operate() {
    while(true) {
        data toC{};
        station_message fromA;
        log_message log{};

        auto *temp = &fromA;
        queueA.pop(temp);
        auto halfway = std::chrono::system_clock::now();

        log.id = fromA.id;
        log.start = fromA.timestamp;
        log.end = halfway;
        queueB.push(&log);

        toC.temp = fromA.val / 3;
        toC.timestamp = std::chrono::system_clock::now();
        shmBC.push(&toC);
    }
}