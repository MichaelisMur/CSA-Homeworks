#pragma once

#include <string>
#include <iostream>
#include <mutex>

static class Printer {
    static std::mutex available;
public:
    static void print(std::string msg) {
        available.lock();
        std::cout << msg;
        available.unlock();
    }
};