//
// Created by jose on 07/09/18.
//

#ifndef ABSTRACTFACTORY_APPLEBUTTON_H
#define ABSTRACTFACTORY_APPLEBUTTON_H


#include "Widget.h"

class AppleButton: public Widget {
public:
    void make(){
        cout << "Apple Button\n";
    }
};



#endif //ABSTRACTFACTORY_APPLEBUTTON_H
