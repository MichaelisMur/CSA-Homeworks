//------------------------------------------------------------------------------
// rectangle.cpp - содержит методы прямоугольника
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "colour.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void Rectangle::In(ifstream &ifst) {
    ifst >> ax >> ay >> bx >> by >> c;
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Rectangle::Out(ofstream &ofst) {
    ofst << "It is a " << GetColour(c) << " Rectangle: a.x = " << ax << ", a.y = " << ay <<
         ", b.x = " << bx << ", b.y = " << by << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double Rectangle::Area() {
    return (bx - ax) * (ay - by);
}
