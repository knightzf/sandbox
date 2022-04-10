#include <iostream>
#include <string>

class Test {
    public:
        Test(int a) {
            this->a = a;
        }
        
        Test(const std::string& b) {
            this->b = b;
        }

    private:
        union {
            int a;
            std::string b;
        };
};

int main() {
    Test a(123);
}
