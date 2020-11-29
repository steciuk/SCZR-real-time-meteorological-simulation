//
// Created by adam on 19.11.2020.
//
#include "../include/Station.h"
#include <iostream>
using namespace std;

/*struct thread_data {
    int thread_id;
    int num;
};*/

Station::Station(int x, int y) {
    this->x = x;
    this->y = y;
    
}

Station::~Station() = default;

ostream &operator<<(ostream &strm, const Station &station) {
    return strm << "(" << station.x << ", " << station.y << ")";
}

/*void *Station::genTemp(void *threadarg) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;

    int num = my_data->num;

    srand(time(nullptr));
    for(int i=0; i<num; i++){
        int result = 10 + (rand() % 40);
        cout << "Thread ID : " << my_data->thread_id << " Station: " << this << " Temp: " << result;
    }

    pthread_exit(NULL);
}*/

