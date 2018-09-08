//
// Created by jose on 07/09/18.
//

#ifndef ABSTRACTFACTORY_LINUXBUTTON_H
#define ABSTRACTFACTORY_LINUXBUTTON_H


#include "Widget.h"

class LinuxButton: public Widget {
public:
    void make(){
        cout << "Linux Button\n";
    }
};


#endif //ABSTRACTFACTORY_LINUXBUTTON_H
