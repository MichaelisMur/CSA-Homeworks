//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include <iostream>
#include "container.h"
#include "colour.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for(int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
int In(container &c, std::ifstream &ifst) {
    while(!ifst.eof()) {
        if(c.len >= container::max_len)
            return 1;
        if((c.cont[c.len] = In(ifst, c.len)) != nullptr) {
            c.len++;
        }
    }
    return 0;
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements.\n";
    for(int i = 0; i < c.len; i++) {
        ofst << "Figure " << i << ": ";
        Out(*(c.cont[i]), ofst);
    }

    QuickSort(c.cont, 0, c.len - 1);

    ofst << "\n\nSorted figures:\n";
    std::string colour, type;
    for (int i = 0; i < c.len; ++i) {
        switch (c.cont[i]->k) {
            case 0:
                colour = GetColour(c.cont[i]->c.c);
                type = "Circle";
                break;
            case 1:
                colour = GetColour(c.cont[i]->r.c);
                type = "Rectangle";
                break;
            case 2:
                colour = GetColour(c.cont[i]->t.c);
                type = "Triangle";
                break;
        }
        ofst << "Figure " << c.cont[i]->len << ": A " << colour << " " << type << ". Area: "
             << Area(*c.cont[i]) << std::endl;
    }
}

//------------------------------------------------------------------------------
// Функция меняет местами элементы массива
void Swap(shape* i, shape* j) {
    shape temp = *i;
    *i = *j;
    *j = temp;
}

//------------------------------------------------------------------------------
// Сотировка слиянием по возрастанию площади фигур
void QuickSort(shape* cont[], int low, int high) {
    if(low >= high)
        return;
    int indexToSwap = low - 1;
    for (int i = low; i < high; ++i) {
        if(Area(*cont[i]) < Area(*cont[high])) {
            Swap(cont[i], cont[++indexToSwap]);
        }
    }
    Swap(cont[high], cont[++indexToSwap]);
    QuickSort(cont, low, indexToSwap - 1);
    QuickSort(cont, indexToSwap + 1, high);
}
