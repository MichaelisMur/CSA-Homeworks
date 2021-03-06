#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// класс, обобщающий все имеющиеся фигуры
class Shape {
public:
    virtual ~Shape() {};
    // Ввод обобщенной фигуры
    static Shape *StaticIn(ifstream &ifdt, int len);
    // Ввод обобщенной фигуры
    virtual void In(ifstream &ifdt) = 0;
    // Вывод обобщенной фигуры
    virtual void Out(ofstream &ofst) = 0;
    // Вычисление площади обобщенной фигуры
    virtual double Area() = 0;
    int len;
};


#endif
