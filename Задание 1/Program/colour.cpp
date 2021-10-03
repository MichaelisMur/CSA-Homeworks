#include <iostream>
#include "colour.h"

// Функция возвращает название цвета по числовому индексу
std::string GetColour(int c) {
    switch(c) {
        case 0:
            return "red";
        case 1:
            return "orange";
        case 2:
            return "yellow";
        case 3:
            return "green";
        case 4:
            return "blue";
        case 5:
            return "darkblue";
        case 6:
            return "purple";
        default:
            return "???";
    }
}