//
// Created by jose on 07/09/18.
//

#ifndef ABSTRACTFACTORY_USER_H
#define ABSTRACTFACTORY_USER_H


#include "Widget.h"
#include "Factory.h"

class User {
private:
    Factory *factory;

public:
    User(Factory *f){
        factory = f;
    }
    void make(){
        Widget *w = factory->createButton();
        w->make();
        w = factory->createTaskBar();
        w->make();
    }
};


#endif //ABSTRACTFACTORY_USER_H
