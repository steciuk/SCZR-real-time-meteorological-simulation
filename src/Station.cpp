//
// Created by adam on 19.11.2020.
//
#include "../include/Station.h"
using namespace std;

Station::Station(int x, int y) {
    this->x = x;
    this->y = y;
    
}

Station::~Station() = default;

ostream &operator<<(ostream &strm, const Station &station) {
    return strm << "(" << station.x << ", " << station.y << ")";
}

