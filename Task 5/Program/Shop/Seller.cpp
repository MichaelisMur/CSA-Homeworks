#pragma once

#include "Client.cpp"
#include "Products.cpp"
#include <semaphore>
#include <list>
#include "Printer.cpp"



using std::list;

class Seller {
private:
    const Products* arrOfProducts;
    int size;
    std::counting_semaphore<1>* wakeUp;
    list<Client*>* clients;
    bool isSleep = false;
    std::counting_semaphore<1>* available;
    bool shopWait = false;
    std::stringstream* ss;
    //Seller* brother;
    //bool hasBrother = false;

public:
    int id;
    Seller(const Products* arrOfProducts, int size, int id) {
        this->arrOfProducts = arrOfProducts;
        this->size = size;
        this->id = id;
        clients = new list<Client*>();
        wakeUp = new std::counting_semaphore<1>(0);
        available = new std::counting_semaphore<1>(1);
        ss = new std::stringstream();
    }
    ~Seller() {
        delete wakeUp;
        delete clients;
        delete available;
        delete ss;
    }
    /*void setBrother(Seller* brother) {
        this->brother = brother;
        hasBrother = true;
    }*/
    std::string getName() {
        return "Seller " + std::to_string(id) + ": ";
    }

    /// <summary>
    /// This method does again and again in a thread that we call in main.
    /// </summary>
    void doInThread() {
        available->acquire();
        if (clients->size() != 0) {
            Client* client = clients->front();
            client->waitClient();
            client->prepareBySeller();
            serveClient(client);
            clients->pop_front();
        }
        if(shopWait || clients->size() == 0) {
            isSleep = true;
            bool longSleep = clients->size() == 0;
            if (longSleep) {
                *ss << getName() << "I sleep!" << std::endl;
                Printer::print(ss->str());
                ss->str("");
            }
            available->release();
            wakeUp->acquire();
            isSleep = false;
            if (longSleep) {
                *ss << getName() << "I am awaken!" << std::endl;
                Printer::print(ss->str());
                ss->str("");
            }
        }
        else {
            available->release();
        }
        doInThread();
    }
    /// <summary>
    /// Checks if seller has the product.
    /// </summary>
    /// <param name="product"></param>
    /// <returns></returns>
    bool canSell(Products product) {
        for (int i = 0; i < size; i++) {
            if (arrOfProducts[i] == product)
                return true;
        }
        return false;
    }
    /// <summary>
    /// That's how the client snands in the queue.
    /// </summary>
    /// <param name="client"></param>
    void getNewClient(Client* client) {
        shopWait = true;
        available->acquire();
        clients->push_back(client);
        available->release();
        shopWait = false;
        *ss << getName() << "The Client " << client->getId() << " get to me!" << std::endl;
        Printer::print(ss->str());
        ss->str("");
        if (isSleep) wakeUp->release();
    }
    /// <summary>
    /// Method creates a vector of products that the seller has and the client needs.
    /// Than it gives this vector to the client.
    /// </summary>
    /// <param name="client"></param>
    void serveClient(Client* client) {
        std::vector<Products>* sellerAllowsForClient = new std::vector<Products>();
        for (int i = 0; i < client->getProductsNumber(); i++) {
            Products temp = client->getProduct(i);
            if (canSell(temp)) {
                sellerAllowsForClient->push_back(temp);
            }
        }
        client->getPermisionForBuying(sellerAllowsForClient);
        *ss << getName() << "I served the Client " << client->getId() << "!" << std::endl;
        Printer::print(ss->str());
        ss->str("");
        /*if (client->getProductsNumber() != sellerAllowsForClient->size() && hasBrother) {
            ///brother->getNewClient(client);
        }*/
    }
};