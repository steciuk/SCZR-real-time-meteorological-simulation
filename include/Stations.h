#ifndef SCZR_STATIONS_H
#define SCZR_STATIONS_H

#include <vector>
#include <string>
#include "../include/Station.h"

using namespace std;

class Stations {
private:
    vector<vector<int>> numMap;
    vector<Station> stations;
    int x, y;
    double density;
    int seed;
public:
    Stations(int x, int y, double density, int seed = 0);
    ~Stations();

    void genMap();
    vector<vector<int>> getNumMap();
    vector<Station> getStations();
    void printNumMap();
    void toFileNumMap(const string& filename);
    void fromFileNumMap(const string &filename);
    void printStations();
};

#endif //SCZR_STATIONS_H
