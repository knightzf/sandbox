#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>

int main(int argc, char* argv[]) {
  struct addrinfo hints, *results = nullptr;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;      // IPv4 or IPv6
  hints.ai_socktype = SOCK_STREAM;  // avoid duplicated addresses
  hints.ai_flags = AI_CANONNAME;    // request the canonical name
  int rval = getaddrinfo("localbmc", NULL, &hints,
                         &results);
  std::cout<<"rval "<< rval << std::endl;
  return 0;
}

