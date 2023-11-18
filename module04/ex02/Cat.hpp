#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 public:
  Cat();
  Cat(Cat &src);
  ~Cat();

  Cat &operator=(Cat &rhs);

  virtual void MakeSound() const;

 private:
  Brain *brain_;
};

#endif  // !CAT_HPP
