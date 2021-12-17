#pragma once

#include "Products.cpp"
#include <vector>
#include <semaphore>
#include "OperatorForProducts.cpp"
#include <iostream>
#include "Printer.cpp"

class Client {
private:
    std::vector<Products>* arrOfProducts;
    std::vector<Products>* buyedProducts;
    std::vector<Products>* sellerAllow;
    std::counting_semaphore<1>* wakeUp;
    std::counting_semaphore<1>* available;
    std::stringstream* ss;
    int id;
public:
    /// <summary>
    /// Id i need to make for an each client a different name to look pretty in console.
    /// </summary>
    /// <param name="id"></param>
    int getId() { return id; }
    void setId(int id) { this->id = id; }
    /// <summary>
    /// Automatically generated object.
    /// </summary>
    Client() {
        arrOfProducts = new std::vector<Products>();
        buyedProducts = new std::vector<Products>();
        wakeUp = new std::counting_semaphore<1>(0);
        available = new std::counting_semaphore<1>(1);
        ss = new std::stringstream();
        const int productsKindsNumber = 10;
        const int maxProductsNumber = 12;
        int productsNumber = rand() % maxProductsNumber + 1;
        for (int i = 0; i < productsNumber; i++) {
            int productKindNumber = rand() % productsKindsNumber;
            Products product = (Products)productKindNumber;
            arrOfProducts->push_back(product);
        }
    }
    ~Client() {
        delete arrOfProducts;
        delete buyedProducts;
        delete sellerAllow;
        delete wakeUp;
        delete available;
        delete ss;
    }
    Client(std::vector<Products>* arrOfProducts) {
        this->arrOfProducts = arrOfProducts;
        this->buyedProducts = new std::vector<Products>();
        wakeUp = new std::counting_semaphore<1>(0);
        available = new std::counting_semaphore<1>(1);
    }
    std::string getName() {
        return "Client " + std::to_string(id) + ": ";
    }
    /// <summary>
    /// This method wakes the client up. It is called from seller to start the buying process which both sides are participating in.
    /// </summary>
    void getPermisionForBuying(std::vector<Products>* products) {
        sellerAllow = products;
        wakeUp->release();
    }
    /// <summary>
    /// This method is for safety.
    /// </summary>
    void waitClient() {
        available->acquire();
        available->release();
    }
    /// <summary>
    /// This method is for safety.
    /// </summary>
    /// <returns></returns>
    void prepareBySeller() {
        available->acquire();
    }
    /// <summary>
    /// This method is for safety.
    /// </summary>
    void makeFree() {
        available->release();
    }
    Products getProduct(int ind) {
        return arrOfProducts->at(ind);
    }
    int getProductsNumber() {
        return arrOfProducts->size();
    }
    /// <summary>
    /// Deletes the products which seller sold us (in sellerAllow, we got it earlier).
    /// </summary>
    void buyProducts() {
        for (int i = 0, j = 0; i < sellerAllow->size(); i++) {
            if (sellerAllow->at(i) == arrOfProducts->at(j)) {
                buyedProducts->push_back(arrOfProducts->at(j));
                arrOfProducts->erase(arrOfProducts->erase(arrOfProducts->begin() + j));
            }
            else {
                j++;
            }
        }
        *ss << getName() << "I bought a part of products!"<<std::endl;
        Printer::print(ss->str());
        ss->str("");
    }
    /// <summary>
    /// This method the client does in thread.
    /// </summary>
    void doInThread() {
        *ss << getName() << "I sleep!" << std::endl;
        Printer::print(ss->str());
        ss->str("");
        wakeUp->acquire();
        *ss << getName() << "I am awaken!" << std::endl;
        Printer::print(ss->str());
        ss->str("");
        buyProducts();
        if (arrOfProducts->size() != 0) {
            available->release();
            doInThread();
        }
        else {
            *ss << getName() << "I bought everything that I wanted!" << std::endl;
            Printer::print(ss->str());
            ss->str("");
            available->release();;
            wakeUp->release();
        }
    }
    std::string toString() {
        std::stringstream* sss = new std::stringstream();
        for (int i = 0; i < arrOfProducts->size(); i++) {
            *sss << arrOfProducts->at(i) << " ";
        }
        return sss->str();
    }
};