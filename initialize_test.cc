#include <iostream>

class A {
public:
    A(int) {}
private:
    A() {
        std::cout << "A" << std::endl;
    }
};

class B {
public:
    B() {
        this->a = A(1);
    }

private:
    A a;
};

int main() {
    B b;
}