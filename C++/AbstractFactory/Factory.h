//
// Created by jose on 07/09/18.
//

#ifndef ABSTRACTFACTORY_FACTORY_H
#define ABSTRACTFACTORY_FACTORY_H


#include "Widget.h"

class Factory {
public:
    virtual Widget *createButton() = 0;
    virtual Widget *createTaskBar() = 0;
};


#endif //ABSTRACTFACTORY_FACTORY_H
