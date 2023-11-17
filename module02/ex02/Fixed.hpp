#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
  int raw_bits_;
  static const int frac_bits_ = 8;

public:
  Fixed();
  Fixed(const int n);
  Fixed(const float n);
  ~Fixed();
  Fixed(const Fixed &src);

  int get_raw_bits(void) const;
  void set_raw_bits(int const raw_bits);

  float ToFloat() const;
  int ToInt() const;

  static Fixed &min(Fixed &a, Fixed &b);
  const static Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  const static Fixed &max(const Fixed &a, const Fixed &b);

  // OPERATOR OVERLOAD

  // Copy Assign
  Fixed &operator=(const Fixed &rhs);

  // Comparisons
  bool operator>(const Fixed &rhs) const;
  bool operator<(const Fixed &rhs) const;
  bool operator>=(const Fixed &rhs) const;
  bool operator<=(const Fixed &rhs) const;
  bool operator==(const Fixed &rhs) const;
  bool operator!=(const Fixed &rhs) const;

  // Arithmetic
  Fixed operator+(const Fixed &rhs) const;
  Fixed operator-(const Fixed &rhs) const;
  Fixed operator*(const Fixed &rhs) const;
  Fixed operator/(const Fixed &rhs) const;

  // Increment/Decrement
  Fixed &operator++();
  Fixed &operator--();
  Fixed operator++(int);
  Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // !FIXED_H
