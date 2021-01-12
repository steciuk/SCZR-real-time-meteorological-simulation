//
// Created by jestemleon on 10.01.2021.
//

#include "ProcessC.h"

[[noreturn]] void ProcessC::operate() {
    data fromB{};
    log_message log{};

    while(true) {
        shmBC.pop(&fromB);
        auto end = std::chrono::system_clock::now();

        log.id = fromB.temp;
        log.start = fromB.timestamp;
        log.end = end;
        queueC.push(&log);
    }
}