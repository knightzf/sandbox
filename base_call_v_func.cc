#include <iostream>

struct A {
    A() {
        add();
    }
    virtual void add() {
        std::cout << "A::add" << std::endl;
    }
};

struct B : A {
    B() {

    }
    void add() override {
        std::cout << "B::add" << std::endl;
    }
};

int main() {
    B b;
}