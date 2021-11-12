#include <iostream>

struct A {
    virtual void add() {
        std::cout << "A::add" << std::endl;
    }

    virtual void addAll() {
        std::cout << "A::addAll" << std::endl;
        add();
    }
};

struct B : A {
    void add() override {
        std::cout << "B::add" << std::endl;
    }

    void addAll() override {
        std::cout << "B::addAll" << std::endl;
        A::addAll();
    }
};

int main() {
    B b;
    b.addAll();
}