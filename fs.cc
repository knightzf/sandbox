#include <filesystem>
#include <iostream>
#include <fcntl.h>
#include <cstdio>
#include <string_view>

int main() {
  namespace fs = std::filesystem;
  //fs::rename("/tmp/a.txt", "/tmp/aaa/b.txt");
  //fs::create_directories("/tmp/aaa/bbb");
  //fs::rename("/tmp/a", "/tmp/b");
  //auto a = fs::path("/tmp/a");
  //auto b = fs::path("/tmp/b");
  //a.swap(b);
  //renameat2(AT_FDCWD, "/tmp/a", AT_FDCWD, "/tmp/b", RENAME_EXCHANGE);
  //fs::create_directory("/tmp/a/");
  //fs::remove_all("/tmp/a/");
  /*std::string_view x = "/tmp/test/";
  if(!x.empty() && x.back() == '/') {
    x.remove_suffix(1);
  }
  auto a = fs::path(x);
  auto b = a.parent_path() / "bb";
  std::cout<<b<<std::endl;*/
  auto a = fs::path("/tmp/a/b");
  std::cout<<a.parent_path().filename()<<std::endl;
}
