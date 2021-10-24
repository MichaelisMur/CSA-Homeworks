#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "shape.h"

// прямоугольник
class Rectangle: public Shape {
public:
    virtual ~Rectangle() {}
    // Ввод параметров прямоугольника из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров прямоугольника
    virtual void Out(ofstream &ofst);
    // Вычисление площади прямоугольника
    virtual double Area();
private:
    int ax, ay;     // Коорднаты x и y левого верхнего угла
    int bx, by;     // Коорднаты x и y правого нижнего угла
    int c;          // Цвет прямоугольника
};

#endif //__rectangle__
