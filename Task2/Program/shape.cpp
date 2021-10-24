//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "iostream"
#include "triangle.h"
#include "circle.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
Shape* Shape::StaticIn(ifstream &ifst, int len) {
    int k;
    ifst >> k;
    Shape* sp = nullptr;
    switch(k) {
        case 1:
            sp = new Circle;
            sp->len = len;
            break;
        case 2:
            sp = new Rectangle;
            sp->len = len;
            break;
        case 3:
            sp = new Triangle;
            sp->len = len;
            break;
    }
    sp->In(ifst);
    return sp;
}
