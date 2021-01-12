//
// Created by jestemleon on 07.01.2021.
//

#ifndef SCZR_ABSTRACTPROCESS_H
#define SCZR_ABSTRACTPROCESS_H


class AbstractProcess {
public:
    [[noreturn]] virtual void operate(int stations, int x, int y) = 0;
};


#endif //SCZR_ABSTRACTPROCESS_H
