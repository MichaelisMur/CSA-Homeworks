#pragma once

#include "Seller.cpp"
#include "Client.cpp"
#include <list>
#include <thread>

using std::list;

/// <summary>
/// Connects seller and client.
/// </summary>
class Shop {
private:
    Seller* firstSeller;
    Seller* secondSeller;
    list<Client*>* clients;

public:
    Shop(Seller* firstSeller, Seller* secondSeller){
        this->firstSeller = firstSeller;
        this->secondSeller = secondSeller;
        clients = new list<Client*>();
    }
    ~Shop() {}
    /// <summary>
    /// Method for pushing client to the shop.
    /// </summary>
    /// <param name="client"></param>
    void letClientIn(Client* client) {
        if (client->getProductsNumber() == 0) {
            return;
        }
        clients->push_back(client);
        pushClientToNeededSeller(client);
    }
    /// <summary>
    /// The client needs to go to the seller if the seller has products that the client needs.
    /// </summary>
    /// <param name="client"></param>
    void pushClientToNeededSeller(Client* client) {
        client->waitClient();
        client->prepareBySeller();
        if (firstSeller->canSell(client->getProduct(0))) {
            firstSeller->getNewClient(client);
        }
        else {
            secondSeller->getNewClient(client);
        }
        client->makeFree();
    }
    /// <summary>
    /// The clients go to the second part of the shop after some time and when they are ready.
    /// </summary>
    void doAfter() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        bool alEmpty = true;
        for (int i = 0; i < clients->size(); i++) {
            clients->front()->waitClient();
            clients->front() -> prepareBySeller();
            if (clients->front()->getProductsNumber() != 0) {
                alEmpty = false;
                clients->front()->makeFree();
                pushClientToNeededSeller(clients->front());
            }
            clients->pop_front();
        }
    }
};