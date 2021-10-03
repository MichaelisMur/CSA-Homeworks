//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include "container.h"

void errMessage() {
    std::cout << "Incorrect command line.\n"
                 "Expected: <command.exe> <infile.txt> <outfile.txt>\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 3) {
        errMessage();
        return 1;
    }

    std::cout << "Start\n\n";
    container c;
    Init(c);

    std::cout << "Filling the container...\n\n";
    std::ifstream ifst(argv[1]);
    if(In(c, ifst)){
        std::cout << "Error. Too many parameters.\n";
    }

    // Вывод содержимого контейнера в файл
    std::ofstream ofst(argv[2]);
    ofst << "Container was successfully filled.\n";
    Out(c, ofst);

    Clear(c);
    std::cout << "Finish!\n";
    return 0;
}
