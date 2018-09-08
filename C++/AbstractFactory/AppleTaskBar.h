//
// Created by jose on 07/09/18.
//

#ifndef ABSTRACTFACTORY_APPLETASKBAR_H
#define ABSTRACTFACTORY_APPLETASKBAR_H


#include "Widget.h"

class AppleTaskBar : public Widget {
public:
    void make(){
        cout << "Apple Task Bar\n";
    }
};



#endif //ABSTRACTFACTORY_APPLETASKBAR_H
