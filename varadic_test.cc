#include <iostream>

template<typename... Ts>
auto sum(Ts&&... vs) {
    return (... + vs);
}

int main()
{
    std::cout << sum(1, 3, 4) << std::endl;
    std::cout << sum(1, 3, 3.5) << std::endl;
}