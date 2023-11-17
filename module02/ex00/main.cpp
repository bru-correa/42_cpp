#include <iostream>

#include "Fixed.hpp"

int main() {
  Fixed a;
  Fixed b(a);
  Fixed c;
  c = b;
  std::cout << a.get_raw_bits() << "\n";
  std::cout << b.get_raw_bits() << "\n";
  std::cout << c.get_raw_bits() << "\n";
}
