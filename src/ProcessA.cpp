//
// Created by jestemleon on 09.01.2021.
//

#include "ProcessA.h"

[[noreturn]] void ProcessA::operate() {
    data toB{};

    while(true) {
        toB.val = 10 + rand() % 10;
        toB.timestamp = std::chrono::system_clock::now();
        shmAB.push(&toB);
        usleep(500000);
    }
}

/*
struct thread_data {
    int thread_id;
    int num;
    chrono::high_resolution_clock::time_point t1;
};

void *GenTemp(void *threadarg) {
    thread_data *my_data;
    my_data = (thread_data *) threadarg;

    int num = my_data->num;
    chrono::high_resolution_clock::time_point t1 = my_data->t1;

    srand(time(nullptr));
    for(int i=0; i<num; i++){
        int result = 10 + (rand() % 10);
        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> time_span = t2 - t1;
        string output =
                "Station ID : " + to_string(my_data->thread_id) +
                " Timestamp: " + to_string(time_span.count()) +
                " Temp: " + to_string(result) + "\n";
        cout << output;
        sleep(5);
    }

    pthread_exit(NULL);
}

int rc;
int i;
chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
for( i = 0; i < 5; i++ ) {
    cout << "main() : creating thread, " << i << endl;
    td[i].thread_id = i;
    td[i].num = 30;
    td[i].t1 = t1;
    rc = pthread_create(&threads[i], NULL, GenTemp, (void *) &td[i]);

    if (rc) {
        cout << "Error:unable to create thread," << rc << endl;
        exit(-1);
    }
}

Stations stations(100, 10, 1.0);
stations.genMap();

int numStations = stations.getStations().size();
pthread_t threads[numStations];
struct thread_data td[numStations];
*/