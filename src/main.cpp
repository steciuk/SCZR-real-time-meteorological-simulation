#include <iostream>
#include "../include/Stations.h"
using namespace std;

int main(){
    Stations stations(100, 10, 0.25);
    stations.genMap();
    stations.toFileNumMap("numMap.txt");
    //stations.printNumMap();
    //stations.fromFileNumMap("numMap.txt");
    //stations.printNumMap();
    stations.printStations();
    return 0;
}
