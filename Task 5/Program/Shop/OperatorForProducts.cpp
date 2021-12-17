#pragma once 

#include <ostream>
#include "Products.cpp"

/// <summary>
/// This i need for method toString in Client.cpp.
/// </summary>
/// <param name="out"></param>
/// <param name="t"></param>
/// <returns></returns>
inline
std::ostream& operator << (std::ostream& out, const Products& t)
{
    switch (t) {
    case Products::POTATO: return (out << "POTATO");
    case Products::BREAD: return (out << "BREAD");
    case Products::ICECREAM: return (out << "ICECREAM");
    case Products::HOTDOG: return (out << "HOTDOG");
    case Products::PIZZA: return (out << "PIZZA");
    case Products::HAMBURGER: return (out << "HAMBURGER");
    case Products::COOKIES: return (out << "COOKIES");
    case Products::PIE: return (out << "PIE");
    case Products::CHEESE: return (out << "CHEESE");
    case Products::MILK: return (out << "MILK");
    }
    return (out);
}