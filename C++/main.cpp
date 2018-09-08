#include <iostream>
#include <string>
#include <vector>
//En el patron observer se crea la Clase Subject como una princiapl ligada a la clase observer
//y los demas observers ligados nada mas al subject asi cualquier cambio el observer le dira al
//subject que notifique a los demas el cambio que se realizo

class Subject {

    std::vector < class Observer * > views;
    int value;

public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void setVal(int val) {
        value = val;
        notify();
    }
    int getVal() {
        return value;
    }
    void notify();
};

class Observer {
    Subject *model;
    int denom;
public:
    Observer(Subject *mod, int div) {
        model = mod;
        denom = div;
        model->attach(this);
    }

    virtual void update() = 0;
protected:

    Subject *getSubject() {
        return model;
    }
    int getDivisor() {
        return denom;
    }
};

void Subject::notify() {
    for (int i = 0; i < views.size(); i++)
        views[i]->update();
}

class DivObserver: public Observer {
public:
    DivObserver(Subject *mod, int div): Observer(mod, div){}
    void update() {
        int v = getSubject()->getVal(), d = getDivisor();
       std::cout << v << " div " << d << " is " << v / d << '\n';
    }
};

class ModObserver: public Observer {
public:
    ModObserver(Subject *mod, int div): Observer(mod, div){}
    void update() {
        int v = getSubject()->getVal(), d = getDivisor();
        std::cout << v << " mod " << d << " is " << v % d << '\n';
    }
};


//El patron builder se utiliza para crear un objeto con siertas especificaciones o sin algunas de esas
//en este caso se crea una guitarra en la que se le pregunta al usuario como la desea ya sea por el numero de cuerdas,
//tipo y marca

class guitar
{
public:
    class builder;
    guitar(int nStrings,std::string brand, std::string type)
            : nStrings{nStrings}, brand{brand}, type{type}
    { }
    int nStrings;
    std::string brand;
    std::string type;
};
class guitar::builder
{
public:
    builder& withNStrings(int value) { nStrings = value; return *this; };
    builder& withBrand(std::string value) { brand = value; return *this; };
    builder& withType(std::string value) { type = value; return *this; };
    guitar build() const
    {
        return guitar{nStrings, brand, type};
    }
private:
    int nStrings = 0;
    std::string brand = "";
    std::string type = "";
};
int main() {
    std::cout << "Create your guitar" << std::endl;
    std::cout << "How many strings do you want" << std::endl;
    int n;
    std::cin >> n;
    std::cout << "Which brand" << std::endl;
    std::string i;
    std::cin >> i;
    std::cout << "Which type(acoustic or electric)" << std::endl;
    std::string j;
    std::cin >>j;
    guitar::builder &a = guitar::builder{}.withNStrings(n)
                                          .withBrand(i)
                                          .withType(j);
    std::cout << "Guitar succesfully created"<<std::endl;

    Subject subj;
    DivObserver divObs1(&subj, 4);
    DivObserver divObs2(&subj, 3);
    ModObserver modObs3(&subj, 3);
    subj.setVal(14);

}
