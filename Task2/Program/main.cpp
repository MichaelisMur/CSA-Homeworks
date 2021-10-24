//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <chrono>

#include "container.h"

void errMessage() {
    std::cout << "Incorrect command line.\n"
                 "Expected: <command.exe> <infile.txt> <outfile.txt>\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    auto start = chrono::steady_clock::now();
    if(argc != 3) {
        errMessage();
        return 1;
    }

    std::cout << "Start\n\n";
    Container c;

    ifstream ifst(argv[1]);
    c.In(ifst);

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[2]);
    ofst1 << "Container was successfully filled.\n";
    c.Out(ofst1);

    cout << "Stop"<< endl;
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}
