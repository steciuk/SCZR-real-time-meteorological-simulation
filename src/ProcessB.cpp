//
// Created by jestemleon on 09.01.2021.
//

#include "ProcessB.h"
#include <cstdlib>
#include <unistd.h>
#include <iostream>

[[noreturn]] void ProcessB::operate(int stations) {
    bool buff = false;
    data toC{};
    for(int i = 0; i < stations; i++) {
        toC.id = i;
        toC.coords[i][0] = toC.coords[i][1] = toC.coords[i][2] = 0;
    }

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

        //toC.id = fromA.id;
        toC.coords[fromA.id][0] = fromA.x;
        toC.coords[fromA.id][1] = fromA.y;
        toC.coords[fromA.id][2] = fromA.val;
        for(int i = 0; i < stations; i++) {
            if(toC.coords[i][0] == 0)
                break;
            buff = true;
        }

        if (buff) {
            toC.timestamp = std::chrono::system_clock::now();
            shmBC.push(&toC);
        }
    }
}