#ifndef FIXED_H
#define FIXED_H

class Fixed {
private:
  int raw_bits_;
  static const int frac_bits_ = 8;

public:
  Fixed();
  ~Fixed();
  Fixed(const Fixed &src);

  Fixed &operator=(const Fixed &rhs);

  int get_raw_bits(void) const;
  void set_raw_bits(int const raw_bits);
};

#endif // !FIXED_H
