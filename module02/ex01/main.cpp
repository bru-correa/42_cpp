#include <iostream>

#include "Fixed.hpp"

int main() {
  Fixed a;
  const Fixed b(10);
  const Fixed c(42.42f);
  const Fixed d(b);
  a = Fixed(1234.4321f);
  std::cout << "--------------- FIXED ---------------\n";
  std::cout << "a is " << a << "\n";
  std::cout << "b is " << b << "\n";
  std::cout << "c is " << c << "\n";
  std::cout << "d is " << d << "\n";
  std::cout << "--------------- INT ---------------\n";
  std::cout << "a is " << a.ToInt() << " as integer\n";
  std::cout << "b is " << b.ToInt() << " as integer\n";
  std::cout << "c is " << c.ToInt() << " as integer\n";
  std::cout << "d is " << d.ToInt() << " as integer\n";
}
