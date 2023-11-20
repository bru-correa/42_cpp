#include <iostream>

#include "whatever.hpp"

int main() {
  std::cout << "--------------- TEST FUNCTIONS ---------------\n";
  int a(42);
  int b(24);
  std::cout << "a: " << a << "\n";
  std::cout << "b: " << b << "\n";
  std::cout << "----- After Swap ----\n";
  swap(a, b);
  std::cout << "a: " << a << "\n";
  std::cout << "b: " << b << "\n";
  std::cout << "----- Min ----\n";
  std::cout << min(a, b) << "\n";
  std::cout << "----- Max ----\n";
  std::cout << max(a, b) << "\n";
}
