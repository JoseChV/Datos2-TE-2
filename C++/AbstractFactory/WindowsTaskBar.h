//
// Created by jose on 07/09/18.
//

#ifndef ABSTRACTFACTORY_WINDOWSTASKBAR_H
#define ABSTRACTFACTORY_WINDOWSTASKBAR_H


#include "Widget.h"

class WindowsTaskBar: public Widget {
public:
    void make(){
        cout << "Windows Task Bar\n";
    }
};


#endif //ABSTRACTFACTORY_WINDOWSTASKBAR_H
