//
// Created by jose on 07/09/18.
//

#ifndef ABSTRACTFACTORY_APPLEFACTORY_H
#define ABSTRACTFACTORY_APPLEFACTORY_H


#include "Factory.h"
#include "AppleButton.h"
#include "AppleTaskBar.h"

class AppleFactory : public Factory {
public:
    Widget *createButton() override {
        return new AppleButton;
    }
    Widget *createTaskBar() override{
        return new AppleTaskBar;

    }
};


#endif //ABSTRACTFACTORY_APPLEFACTORY_H
