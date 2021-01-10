//
// Created by jestemleon on 07.01.2021.
//

#ifndef SCZR_ABSTRACTPROCESS_H
#define SCZR_ABSTRACTPROCESS_H


class AbstractProcess {
public:
    [[noreturn]] virtual void operate() = 0;
};


#endif //SCZR_ABSTRACTPROCESS_H
