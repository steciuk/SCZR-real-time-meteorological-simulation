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
    double temp = my_data->startTemp;
    double maxStep = my_data->maxStep;
    int minTemp = my_data->minTemp;
    int maxTemp = my_data->maxTemp;
    srand(my_data->seed);

    //station_message toB{};

    while(true) {
        station_message toB{};
        double f = (double)rand() / RAND_MAX;
        double step = -maxStep + f * 2 * maxStep;
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
        sleep(1 + rand() % 3);
    }

    pthread_exit(NULL);
}


[[noreturn]] void ProcessA::operate(int stations) {
    //map params
    int seed = 1;
    double density = 1.0; // min: 0, max: 1.0
    int x = 2;
    int y = 2;
    // density 1.0 oraz rozmiar 2x2 = 4 watki

    //gen params
    double maxTempStep = 1.0;
    int minTemp = -10;
    int maxTemp = 40;

    if(seed == 0)
        srand(time(nullptr));
    else
        srand(seed);

    int maxStations = stations;
    int stationsData[maxStations][3]; //0:x, 1:y, 2:startTemp
    int numMap[y][x];
    int numStations = 0;

    //cords
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            double r = ((double)rand() / RAND_MAX);
            if(r < density) {
                stationsData[numStations][0] = j;
                stationsData[numStations][1] = i;
                numStations++;
                numMap[i][j] = 1;
            }else
                numMap[i][j] = 0;
        }
    }

    //print stations map
//    for(int i=0; i<y; i++) {
//        for(int j=0; j<y; j++)
//            cout << numMap[i][j];
//
//        cout << endl;
//    }

    //startig temps
    for(int i=0; i < numStations; i++){
        int startingTemp = (rand() % maxTemp) + minTemp;
        stationsData[i][2] = startingTemp;
    }

    pthread_t threads[numStations];
    thread_data td[numStations];
    int rc;
    int iter;

    for( iter = 0; iter < maxStations; iter++ ) {
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

        rc = pthread_create(&threads[iter], NULL, RunStation, (void *) &td[iter]);

        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    while(true){} //to properly log every message, it has to work in background
}