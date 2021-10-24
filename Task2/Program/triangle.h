#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "shape.h"

//------------------------------------------------------------------------------
// треугольник
class Triangle: public Shape {
public:
    virtual ~Triangle() {}
    // Ввод параметров треугольника из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров треугольника
    virtual void Out(ofstream &ofst);
    // Вычисление площади треугольника
    virtual double Area();
private:
    int ax, ay; // коорднаты x и y 1-го угла
    int bx, by; // коорднаты x и y 2-го угла
    int cx, cy; // коорднаты x и y 3-го угла
    int c; // цвет
};

#endif //__triangle__
