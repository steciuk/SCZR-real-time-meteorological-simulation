//
// Created by jestemleon on 10.01.2021.
//

#include "ProcessC.h"
#include <iostream>

[[noreturn]] void ProcessC::operate(int stations) {
    data fromB{};

    while(true) {
        log_message log{};

        shmBC.pop(&fromB);
        auto end = std::chrono::system_clock::now();

        log.start = fromB.timestamp;
        log.end = end;
        queueC.push(&log);
    }
}