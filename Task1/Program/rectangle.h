#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>

// Прямоугольник
struct rectangle {
    int ax, ay;     // Коорднаты x и y левого верхнего угла
    int bx, by;     // Коорднаты x и y правого нижнего угла
    int c;          // Цвет прямоугольника
};

// Ввод параметров прямоугольника из файла
void In(rectangle &r, std::ifstream &ifst);

// Вывод параметров прямоугольника в форматируемый поток
void Out(rectangle &r, std::ofstream &ofst);

// Вычисление периметра прямоугольника
double Area(rectangle &r);

#endif //__rectangle__
