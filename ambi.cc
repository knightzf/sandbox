#include <iostream>
#include <functional>
#include <optional>

/*template<typename T, typename... Vs>
void test(std::optional<T>&& t, Vs&&... vs)
{
}


template<typename T, typename... Vs>
void test(T&& t, Vs&&... vs)
{
}

void f()
{
}

int main() {
  test<int>(1);
  test<std::function<void()>>(f);
}*/

template <typename T>
struct Managed
{

    template <typename Drop>
    class HandleF
    {
      public:
        template <typename... Vs>
        constexpr explicit HandleF(std::optional<T>&& maybeV, Vs&&... vs)
        {
          std::cout<<"11"<<std::endl;
        }

        template <typename... Vs>
        constexpr explicit HandleF(T&& maybeV, Vs&&... vs)
        {
          std::cout<<"22"<<std::endl;
        }
    };
};

struct Wrapper
{
  void operator()(std::function<void()>&& f) { f(); }
};

void f()
{
}

struct CloseFd {
  void operator()(int&& fd) { }
};
using Fd = Managed<int>::HandleF<CloseFd>;

template <typename T>
struct X {
    X(T t) {
    }

    X(std::optional<T> t) {
    }
};

struct Y
{};

int main()
{
  //Managed<std::function<void()>>::HandleF<Wrapper> x(f);
  //Fd(1);
  X<std::function<void()>> x(f);
  //Y y;
  //X<Y> x(y);
}
