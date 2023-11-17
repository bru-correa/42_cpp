#include "Fixed.hpp"

#include <math.h>

#include <iostream>

Fixed::Fixed() : raw_bits_(0) { std::cout << "Default constructor called\n"; };

Fixed::Fixed(const int n) : raw_bits_(n << frac_bits_) {
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float n) {
  std::cout << "Float constructor called\n";
  set_raw_bits(n * roundf(1 << frac_bits_));
}

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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.ToFloat();
  return out;
}

int Fixed::get_raw_bits() const { return raw_bits_; }

void Fixed::set_raw_bits(const int raw_bits) { raw_bits_ = raw_bits; }

int Fixed::ToInt() const { return get_raw_bits() >> frac_bits_; }

float Fixed::ToFloat() const {
  return get_raw_bits() / (float)(1 << frac_bits_);
}
