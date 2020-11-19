#ifndef SCZR_STATION_H
#define SCZR_STATION_H

#include <fstream>

using namespace std;

class Station {
private:
    int x, y;
public:
    Station(int x, int y);
    ~Station();

    friend ostream& operator<<(ostream &strm, const Station& station);
};


#endif //SCZR_STATION_H
