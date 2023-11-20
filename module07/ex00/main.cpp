#include <iostream>

#include "Whatever.hpp"

int main() {
  int a(42);
  int b(24);
  std::cout << "a: " << a << "\n";
  std::cout << "b: " << b << "\n";
  std::cout << "----- After Swap ----\n";
  swap(a, b);
  std::cout << "a: " << a << "\n";
  std::cout << "b: " << b << "\n";
}
