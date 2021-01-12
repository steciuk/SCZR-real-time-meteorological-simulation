//
// Created by jestemleon on 09.01.2021.
//

#include "ProcessA.h"
#include <cstdlib>

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
};

void *RunStation(void *threadarg) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;
    int id = my_data->id;
    int x = my_data->x;
    int y = my_data->y;
    double temp = my_data->startTemp;
    double maxStep = my_data->maxStep;
    int minTemp = my_data->minTemp;
    int maxTemp = my_data->maxTemp;
    srand(my_data->seed);

    data toB{};
    int i = 0;

    while(i < 3) {
        double f = (double)rand() / RAND_MAX;
        double step = -maxStep + f * 2 * maxStep;
        temp += step;
        if(temp > maxTemp)
            temp = maxTemp;
        else if(temp < minTemp)
            temp = minTemp;

        /* do B przekazywane bedzie:
        temp
         x
         y
        */

//      toB.temp = temp;
//      toB.timestamp = std::chrono::system_clock::now();
//      shmAB.push(&toB);
        usleep(500000);
        i++;
    }

    pthread_exit(NULL);
}


[[noreturn]] void ProcessA::operate() {
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

    int maxStations = x*y;
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
    for(int i=0; i<numStations; i++){
        int startingTemp = (rand() % maxTemp) + minTemp;
        stationsData[i][2] = startingTemp;
    }

    pthread_t threads[numStations];
    struct thread_data td[numStations];
    int rc;
    int iter;

    for( iter = 0; iter < numStations; iter++ ) {
        cout <<"creating thread: " << iter << endl;
        td[iter].id = iter;
        td[iter].x = stationsData[iter][0];
        td[iter].y = stationsData[iter][1];
        td[iter].startTemp = stationsData[iter][2];
        td[iter].maxStep = maxTempStep;
        td[iter].minTemp = minTemp;
        td[iter].maxTemp = maxTemp;
        td[iter].seed = seed;

        rc = pthread_create(&threads[iter], NULL, RunStation, (void *) &td[iter]);

        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}