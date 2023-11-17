#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : raw_bits_(0) { std::cout << "Default constructor called\n"; };

Fixed::Fixed(const Fixed &src) {
  std::cout << "Copy constructor called\n";
  *this = src;
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; };

Fixed &Fixed::operator=(const Fixed &rhs) {
  std::cout << "Copy Assignment operator callled\n";
  if (this != &rhs)
    this->raw_bits_ = rhs.get_raw_bits();
  return *this;
}

int Fixed::get_raw_bits() const {
  std::cout << "get_raw_bits member function called\n";
  return raw_bits_;
}

void Fixed::set_raw_bits(const int raw_bits) { raw_bits_ = raw_bits; }
