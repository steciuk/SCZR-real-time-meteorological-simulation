//
// Created by adam on 19.11.2020.
//

#include "../include/Stations.h"
#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <string>

Stations::Stations(int x, int y, double density, int seed) {
    this->x = x;
    this->y = y;
    this->density = density;
    this->seed = seed;

    this->numMap.resize(y, vector<int>(x,0));
}

Stations::~Stations()= default;

void Stations::genMap(){
    if(seed == 0)
        srand(time(nullptr));
    else
        srand(seed);

    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            double r = ((double)rand() / RAND_MAX);
            if(r < density) {
                numMap[i][j] = 1;
                stations.emplace_back(Station(j, i));
            }else
                numMap[i][j] = 0;
        }
    }
}

vector<vector<int>> Stations::getNumMap() {
    return numMap;
}

void Stations::printNumMap() {
    for(const auto& i : numMap) {
        for(const auto& j: i)
            cout << j;

        cout << endl;
    }
}

void Stations::toFileNumMap(const string& filename) {
    ofstream f;
    f.open(filename);
    for(const auto& i : numMap) {
        for(const auto& j: i)
            f << j;

        f << endl;
    }
    f.close();
}

void Stations::fromFileNumMap(const string& filename) {
    ifstream f(filename);
    if(f.is_open()) {
        string line;
        int lineNum = 0;
        while(getline(f, line)) {
            for (int i = 0; i < line.size(); i++) {
                numMap[lineNum][i] = line[i] - 48; //no za nic mi tu nie działa konwersja char na int. Wszystkiego już próbowałem :c
            }
            lineNum++;
        }

        f.close();
    }
}

void Stations::printStations() {
    for(const auto& i : stations) {
        cout << i << endl;
    }
}

vector<Station> Stations::getStations() {
    return stations;
}

