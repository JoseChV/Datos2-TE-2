//
// Created by jose on 07/09/18.
//

#ifndef ABSTRACTFACTORY_LINUXFACTORY_H
#define ABSTRACTFACTORY_LINUXFACTORY_H


#include "Factory.h"
#include "LinuxButton.h"
#include "LinuxTaskBar.h"

class LinuxFactory: public Factory {
public:
    Widget *createButton() override {
        return new LinuxButton;
    }
    Widget *createTaskBar() override{
        return new LinuxTaskBar;

    }
};


#endif //ABSTRACTFACTORY_LINUXFACTORY_H
