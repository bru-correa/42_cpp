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

  Fixed &operator=(const Fixed &rhs);

  int get_raw_bits(void) const;
  void set_raw_bits(int const raw_bits);

  float ToFloat() const;
  int ToInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // !FIXED_H
