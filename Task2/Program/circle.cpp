//------------------------------------------------------------------------------
// circle.cpp - содержит методы прямоугольника
//------------------------------------------------------------------------------

#define _USE_MATH_DEFINES
#include <math.h>
#include "circle.h"
#include "colour.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void Circle::In(ifstream &ifst) {
    ifst >> r >> x >> y >> c;
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Circle::Out(ofstream &ofst) {
    ofst << "It is a " << GetColour(c) << " Circle: r = " << r << ", O.x = " << x <<
         ", O.y = " << y << "\n";
}

//------------------------------------------------------------------------------
// Вычисление площади прямоугольника
double Circle::Area() {
    return M_PI * r * r;
}