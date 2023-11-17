#include <iostream>

#include "Fixed.hpp"

static std::string GetBoolString(bool b) { return b ? "true" : "false"; }

static void TestComparison() {
  Fixed a(5.5f);
  Fixed b(6.225f);
  std::cout << "----------Testing comparisons----------\n";
  std::cout << "Value of a: " << a << "\n"
            << "Value of b: " << b << "\n";
  std::cout << "a < b: " << GetBoolString(a < b) << "\n";
  std::cout << "a > b: " << GetBoolString(a > b) << "\n";
  std::cout << "a >= b: " << GetBoolString(a >= b) << "\n";
  std::cout << "a <= b: " << GetBoolString(a <= b) << "\n";
  std::cout << "a == b: " << GetBoolString(a == b) << "\n";
  std::cout << "a != b: " << GetBoolString(a != b) << "\n";
}

static void TestArithmetic() {
  Fixed a(5.5f);
  Fixed b(6.225f);
  std::cout << "----------Testing arithmetic----------\n";
  std::cout << "Value of a: " << a << "\n";
  std::cout << "Value of b: " << b << "\n";
  std::cout << "a + b = " << a + b << "\n";
  std::cout << "a - b = " << a - b << "\n";
  std::cout << "a * b = " << a * b << "\n";
  std::cout << "a / b = " << a / b << "\n";
  std::cout << "a++ = " << a++ << "\n";
  std::cout << "++a = " << ++a << "\n";
  std::cout << "a-- = " << a-- << "\n";
  std::cout << "--a = " << --a << "\n";
}

static void TestMinMax() {
  Fixed a(5.5f);
  Fixed b(6.225f);
  std::cout << "----------Testing Min and Max----------\n";
  std::cout << "Value of a: " << a << "\n";
  std::cout << "Value of b: " << b << "\n";
  std::cout << "min: " << Fixed::min(a, b) << "\n";
  std::cout << "max: " << Fixed::max(a, b) << "\n";
}

int main() {
  TestComparison();
  TestArithmetic();
  TestMinMax();
}
