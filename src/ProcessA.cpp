//
// Created by jestemleon on 09.01.2021.
//

#include "ProcessA.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

struct thread_data {
    int id;
    int x;
    int y;
    int startTemp;
    double maxStep;
    int minTemp;
    int maxTemp;
    int seed;
    SharedQueue *mq;
};

void *RunStation(void *threadarg) {
    thread_data *my_data;
    my_data = (thread_data *) threadarg;
    int id = my_data->id;
    int x = my_data->x;
    int y = my_data->y;
    float temp = my_data->startTemp;
    float maxStep = my_data->maxStep;
    int minTemp = my_data->minTemp;
    int maxTemp = my_data->maxTemp;
    srand(my_data->seed);

    while(true) {
        station_message toB{};
        float f = (float)rand() / RAND_MAX;
        float step = -maxStep + f * 2 * maxStep;
        temp += step;
        if(temp > maxTemp)
            temp = maxTemp;
        else if(temp < minTemp)
            temp = minTemp;

        toB.id = id;
        toB.x = x;
        toB.y = y;
        toB.val = temp;
        toB.timestamp = std::chrono::system_clock::now();
        my_data->mq->push(&toB);
        //sleep(1 + rand() % 3);
    }
}

[[noreturn]] void ProcessA::operate(int stations) {
    //map params
    int seed = 0;
    int x = 20;
    int y = 20;

    //gen params
    float maxTempStep = 1.0;
    int minTemp = -10;
    int maxTemp = 40;

    if(seed == 0)
        srand(time(nullptr));
    else
        srand(seed);

    int stationsData[stations][3]; //0:x, 1:y, 2:startTemp
    int numMap[x][y];

    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            numMap[i][j] = 0;

    int rx = 0;
    int ry = 0;
    for(int i=0; i<stations; i++){
        do {
            rx = (rand() % x);
            ry = (rand() % y);
        }while(numMap[rx][ry] != 0);

        stationsData[i][0] = rx;
        stationsData[i][1] = ry;
        numMap[rx][ry] = 1;
    }

    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++)
            cout << numMap[i][j];

        cout << endl;
    }

    //starting temps
    for(int i=0; i < stations; i++){
        int startingTemp = (rand() % maxTemp) + minTemp;
        stationsData[i][2] = startingTemp;
    }

    pthread_t threads[stations];
    thread_data td[stations];
    int rc;
    int iter;

    for( iter = 0; iter < stations; iter++ ) {
        cout <<"creating thread: " << iter << endl;
        td[iter].id = iter;
        td[iter].x = stationsData[iter][0];
        td[iter].y = stationsData[iter][1];
        td[iter].startTemp = stationsData[iter][2];
        td[iter].maxStep = maxTempStep;
        td[iter].minTemp = minTemp;
        td[iter].maxTemp = maxTemp;
        td[iter].seed = seed;
        td[iter].mq = &queueA;

        rc = pthread_create(&threads[iter], nullptr, RunStation, (void *) &td[iter]);

        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    while(true){} //to properly log every message, it has to work in background
}