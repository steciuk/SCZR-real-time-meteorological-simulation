//
// Created by jestemleon on 09.01.2021.
//

#include "ProcessB.h"
#include <cstdlib>
#include <unistd.h>
#include <iostream>

[[noreturn]] void ProcessB::operate(int stations) {
    data toC{};

    while(true) {
        station_message fromA;
        log_message log{};

        auto *temp = &fromA;
        queueA.pop(temp);
        auto halfway = std::chrono::system_clock::now();

        log.id = fromA.id;
        log.start = fromA.timestamp;
        log.end = halfway;
        queueB.push(&log);

        toC.coords[fromA.id][0] = fromA.x;
        toC.coords[fromA.id][1] = fromA.y;
        toC.temp[fromA.id] = fromA.val;
        toC.timestamp = std::chrono::system_clock::now();
        shmBC.push(&toC);
    }
}