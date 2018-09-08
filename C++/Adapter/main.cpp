#include <iostream>
using namespace std;

typedef int Coordinate;
typedef int Dimension;

// Interfaz de rectangulos
class Rectangle {

public:
    virtual void draw() = 0;

};

// Hacer el rectangulo
class MakeRectangle {

    Coordinate xx1, xx2, yy1, yy2;

public:
    MakeRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2)
    {
        xx1 = x1;
        yy1 = y1;
        xx2 = x2;
        yy2 = y2;
        cout << "Nuevo rectangulo creado, sus puntos son: (" << xx1 << "," << yy1 << ") y " <<
             "(" << xx2 << "," << yy2 << ")" << endl;
    }

    Coordinate getXx1() const {
        return xx1;
    }

    Coordinate getXx2() const {
        return xx2;
    }

    Coordinate getYy1() const {
        return yy1;
    }

    Coordinate getYy2() const {
        return yy2;
    }


};

// adaptador del rectangulo
class RectangleAdapter: public Rectangle, private MakeRectangle {

public:

    RectangleAdapter(MakeRectangle *R):
            MakeRectangle(R->getXx1(), R->getYy1(), R->getXx2() - R->getXx1(), R->getYy2() - R->getYy1())
    {
        cout << "Adaptando el rectangulo de puntos de cordenadas a dimensiones  (" << R->getXx1() << ","
        << R->getYy1() <<
             "), ancho = " << R->getXx2() - R->getXx1() << ", alto = " << R->getYy2() - R->getYy1() << endl;
    }

    virtual void draw()
    {
        cout << "El programa ya podrá leer al rectangulo a manera de dimensiones" << endl;

    }
};


int main() {

    MakeRectangle *R = new MakeRectangle(120, 200, 180, 240);
    RectangleAdapter *A = new RectangleAdapter(R);
    A->draw();
    cout << "Ejemplo tomado de: https://sourcemaking.com/design_patterns/adapter/cpp/1"<< endl;

}