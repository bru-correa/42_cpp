#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(WrongCat &src);
  ~WrongCat();

  WrongCat &operator=(WrongCat &rhs);

  void MakeSound() const;
};

#endif  // !WRONG_CAT_HPP
