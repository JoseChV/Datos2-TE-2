//
// Created by jose on 07/09/18.
//

#ifndef ABSTRACTFACTORY_WINDOWSFACTORY_H
#define ABSTRACTFACTORY_WINDOWSFACTORY_H


#include "Widget.h"
#include "Factory.h"
#include "WindowsButton.h"
#include "WindowsTaskBar.h"


class WindowsFactory: public Factory {
public:
    Widget *createButton() override {
        return new WindowsButton;
    }
    Widget *createTaskBar() override{
        return new WindowsTaskBar;

    }
};

#endif //ABSTRACTFACTORY_WINDOWSFACTORY_H
