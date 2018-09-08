//
// Created by jose on 07/09/18.
//

#ifndef ABSTRACTFACTORY_WINDOWSBUTTON_H
#define ABSTRACTFACTORY_WINDOWSBUTTON_H


#include "Widget.h"

class WindowsButton: public Widget {
public:
    void make(){
        cout << "Windows Button\n";
    }
};



#endif //ABSTRACTFACTORY_WINDOWSBUTTON_H
