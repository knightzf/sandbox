#include <iostream>
#include <thread>

int main() {
  std::thread t;
  if(t.joinable()) {
    std::cout<<"join"<<std::endl;
    t.join();
  } else {
    std::cout<<"not join"<<std::endl;
  }
}
