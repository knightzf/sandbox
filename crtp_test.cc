#include <iostream>

template<typename T>
class Priceable {
    double net;

    T& derived() {
        return *static_cast<T*>(this);
    }

public:
    Priceable(double n) : net{ n } {}

    double get_price() {
        return net * (1 + derived().tax_value());
    }

    // double tax_value() { 
    //     return .1; 
    // }
};

class Book : public Priceable<Book> {
public:
    Book(double n) : Priceable{ n } {}

    double tax_value() { return 0.0; }
};

int main() {
    Book b{ 50.0 };
    std::cout << b.get_price() << std::endl;
}