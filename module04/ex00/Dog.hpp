#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(Dog &src);
  ~Dog();

  Dog &operator=(Dog &rhs);

  virtual void MakeSound() const;
};

#endif  // !DOG_HPP
