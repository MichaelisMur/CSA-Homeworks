#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "shape.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container {
public:
    Container();
    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void In(ifstream &ifst);
    // Вывод содержимого контейнера в указанный поток
    void Out(ofstream &ofst);
    // Сотировка слиянием по возрастанию площади фигур
    void QuickSort(Shape *cont[], int low, int high);
    void Swap(int i, int j);
private:
    void Clear();    // Очистка контейнера от данных
    Shape* storage[10000];
    int len; // текущая длина
};

#endif
