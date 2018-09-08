#include <iostream>
#include "Widget.h"
#include "Factory.h"
#include "LinuxFactory.h"
#include "User.h"
#include "WindowsFactory.h"
#include "AppleFactory.h"

int main() {
    Factory *factory;
    //if usuario utiliza linux:
    factory = new LinuxFactory;
    User *linuxUser = new User(factory);
    linuxUser->make();
    //elif usuario utiliza windows:
    factory = new WindowsFactory;
    User *windowsUser = new User(factory);
    windowsUser->make();
    //else usuario usa apple:
    factory = new AppleFactory;
    User *appleUser = new User(factory);
    appleUser->make();
}