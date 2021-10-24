//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "iostream"
#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container(): len{0} { }

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream &ifst) {
    while(!ifst.eof()) {
        if((storage[len] = Shape::StaticIn(ifst, len)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        ofst << "Figure " << i << ": ";
        storage[i]->Out(ofst);
    }

    QuickSort(storage, 0, len - 1);

    ofst << "\n\nSorted figures:\n";
    std::string colour, type;
    for (int i = 0; i < len; ++i) {
        ofst << "Figure " << storage[i]->len << ". Area: "
             << storage[i]->Area() << std::endl;
    }
}

//------------------------------------------------------------------------------
// Функция меняет местами элементы массива
void Container::Swap(int i, int j) {
    Shape* temp = storage[i];
    storage[i] = storage[j];
    storage[j] = temp;
}

//------------------------------------------------------------------------------
// Сотировка слиянием по возрастанию площади фигур
void Container::QuickSort(Shape* cont[], int low, int high) {
    if(low >= high)
        return;
   int indexToSwap = low - 1;
    for (int i = low; i < high; ++i) {
        if((*cont[i]).Area() < (*cont[high]).Area()) {
            Swap(i, ++indexToSwap);
        }
    }
    Swap(high, ++indexToSwap);
    QuickSort(cont, low, indexToSwap - 1);
    QuickSort(cont, indexToSwap + 1, high);
}
