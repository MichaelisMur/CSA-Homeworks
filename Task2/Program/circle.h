#ifndef __circle__
#define __circle__

//------------------------------------------------------------------------------
// circle.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "shape.h"

// прямоугольник
class Circle: public Shape {
public:
    virtual ~Circle() {}
    // Ввод параметров прямоугольника из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров прямоугольника
    virtual void Out(ofstream &ofst);
    // Вычисление площади прямоугольника
    virtual double Area();
private:
    int x; // x координата центра
    int y; // y координата центра
    int r; // Радиус
    int c; // Цвет
};

#endif //__circle__
