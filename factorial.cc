#include <iostream>

template <int N>
class Factorial {
public:
    constexpr static int value = N * Factorial<N-1>::value;
};

template <>
class Factorial<1> {
public:
    constexpr static int value = 1;
};

int main()
{
    std::cout << Factorial<4>::value << std::endl;
}