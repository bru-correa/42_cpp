#include "Fixed.hpp"

#include <math.h>

#include <iostream>

Fixed::Fixed() : raw_bits_(0){};

Fixed::Fixed(const int n) : raw_bits_(n << frac_bits_) {}

Fixed::Fixed(const float n) { set_raw_bits(n * roundf(1 << frac_bits_)); }

Fixed::Fixed(const Fixed &src) { *this = src; }

Fixed::~Fixed(){};

int Fixed::get_raw_bits() const { return raw_bits_; }

void Fixed::set_raw_bits(const int raw_bits) { raw_bits_ = raw_bits; }

int Fixed::ToInt() const { return get_raw_bits() >> frac_bits_; }

float Fixed::ToFloat() const {
  return get_raw_bits() / (float)(1 << frac_bits_);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return a > b ? a : b;
}

// OPERATOR OVERLOAD

// Copy Assign
Fixed &Fixed::operator=(const Fixed &rhs) {
  if (this != &rhs)
    this->raw_bits_ = rhs.get_raw_bits();
  return *this;
}

// Comparisons
bool Fixed::operator>(const Fixed &rhs) const {
  return this->get_raw_bits() > rhs.get_raw_bits() ? true : false;
}

bool Fixed::operator<(const Fixed &rhs) const {
  return this->get_raw_bits() < rhs.get_raw_bits() ? true : false;
}

bool Fixed::operator>=(const Fixed &rhs) const {
  return this->get_raw_bits() >= rhs.get_raw_bits() ? true : false;
}

bool Fixed::operator<=(const Fixed &rhs) const {
  return this->get_raw_bits() <= rhs.get_raw_bits() ? true : false;
}

bool Fixed::operator==(const Fixed &rhs) const {
  return this->get_raw_bits() == rhs.get_raw_bits() ? true : false;
}

bool Fixed::operator!=(const Fixed &rhs) const {
  return this->get_raw_bits() != rhs.get_raw_bits() ? true : false;
}

// Arithmetic
Fixed Fixed::operator+(const Fixed &rhs) const {
  Fixed result;
  result.set_raw_bits(this->get_raw_bits() + rhs.get_raw_bits());
  return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
  Fixed result;
  result.set_raw_bits(this->get_raw_bits() - rhs.get_raw_bits());
  return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
  return Fixed(this->ToFloat() * rhs.ToFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
  return Fixed(this->ToFloat() / rhs.ToFloat());
}

// Increment/Decrement
Fixed &Fixed::operator++() {
  raw_bits_++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed copy(*this);
  copy.raw_bits_++;
  return copy;
}

Fixed &Fixed::operator--() {
  raw_bits_--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed copy(*this);
  copy.raw_bits_--;
  return copy;
}

// I/O Stream
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.ToFloat();
  return out;
}
