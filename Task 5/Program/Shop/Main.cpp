// Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once

#include <iostream>
#include <thread>
#include "Products.cpp"
#include "Seller.cpp"
#include "Shop.cpp"
#include "Printer.cpp"



using std::thread;
using std::cout;
using std::endl;

std::mutex Printer::available;

/// <summary>
/// *ss << ...; then Printer.print(...); then ss->str("") is an algorithm that prints something to console.
/// </summary>
/// <returns></returns>
int main()
{
    std::stringstream* ss = new std::stringstream();
    const Products* productsOfFirstSeller = new Products[]
    { Products::POTATO, Products::BREAD, Products::ICECREAM, Products::HOTDOG, Products::PIZZA };
    int firstSize = 5;
    const Products* productsOfSecondSeller = new Products[]
    { Products::HAMBURGER, Products::COOKIES, Products::PIE, Products::CHEESE, Products::MILK };
    int secondSize = 5;
    Seller* first = new Seller(productsOfFirstSeller, firstSize, 1);
    Seller* second = new Seller(productsOfSecondSeller, secondSize, 2);
    //first->setBrother(second);
    //second->setBrother(first);
    Shop* shop = new Shop(first, second);
    
    thread firstSellerThread([first]() {first->doInThread(); });
    thread secondSellerThread([second]() {second->doInThread(); });
    *ss << "Sellers are ready!" << endl << endl;
    int c;
    //do {
    *ss << "Enter a number of new clients you want to create!" << endl <<
        "Or Enter a non positive number to close the program!" << endl;
    Printer::print(ss->str());
    ss->str("");
    std::cin >> c;
    if (c < 0) return 0;
    *ss << endl;
    Printer::print(ss->str());
    ss->str("");
    Client** clients = new Client*[c];
    for (int i = 0; i < c; i++) {
        clients[i] = new Client();
        clients[i]->setId(i + 1);
        *ss << clients[i]->getName() << clients[i]->toString() << endl;
    }
    *ss << std::to_string(c) << " clients were successfully created!" << endl;
    *ss << "Press any key and Enter to push clients to the shop." << endl << 
        "Do the same after when you want to close the program." << endl;
    Printer::print(ss->str());
    ss->str("");
    std::string k;
    std::cin >> k;
    *ss << endl;
    Printer::print(ss->str());
    ss->str("");
    thread** threadsOfClients = new thread*[c];
    for (int i = 0; i < c; i++) {
        Client* tempClient = clients[i];
        thread* clientThread = new thread([tempClient](){tempClient->doInThread(); });
        threadsOfClients[i] = clientThread;
        shop->letClientIn(clients[i]);
    }
    firstSellerThread.detach();
    secondSellerThread.detach();
    for (int i = 0; i < c; i++) {
        threadsOfClients[i]->detach();
    }
    shop->doAfter();
    std::cin >> k;
    //} while (c > 0);
    
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
