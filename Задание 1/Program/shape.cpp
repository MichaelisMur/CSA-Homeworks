//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "shape.h"
#include "iostream"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
shape* In(std::ifstream &ifst, int len) {
    shape *sp;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            sp = new shape;
            sp->len = len;
            sp->k = shape::CIRCLE;
            In(sp->c, ifst);
            return sp;
        case 2:
            sp = new shape;
            sp->k = shape::RECTANGLE;
            sp->len = len;
            In(sp->r, ifst);
            return sp;
        case 3:
            sp = new shape;
            sp->k = shape::TRIANGLE;
            sp->len = len;
            In(sp->t, ifst);
            return sp;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(shape &s, std::ofstream &ofst) {
    switch(s.k) {
        case shape::CIRCLE:
            Out(s.c, ofst);
            break;
        case shape::RECTANGLE:
            Out(s.r, ofst);
            break;
        case shape::TRIANGLE:
            Out(s.t, ofst);
            break;
        default:
            ofst << "Incorrect figure!" << std::endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление площади фигуры
double Area(shape &s) {
    switch(s.k) {
        case shape::CIRCLE:
            return Area(s.c);
        case shape::RECTANGLE:
            return Area(s.r);
        case shape::TRIANGLE:
            return Area(s.t);
        default:
            return 0.0;
    }
}
