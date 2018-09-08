//
// Created by jose on 07/09/18.
//

#ifndef ABSTRACTFACTORY_LINUXTASKBAR_H
#define ABSTRACTFACTORY_LINUXTASKBAR_H


#include "Widget.h"

class LinuxTaskBar: public Widget {
public:
    void make(){
        cout << "Linux Task Bar\n";
    }
};


#endif //ABSTRACTFACTORY_LINUXTASKBAR_H
