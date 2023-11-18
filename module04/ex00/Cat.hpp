#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
 public:
  Cat();
  Cat(Cat &src);
  ~Cat();

  Cat &operator=(Cat &rhs);

  virtual void MakeSound() const;
};

#endif  // !CAT_HPP
