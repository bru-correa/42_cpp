#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <string>

class WrongAnimal {
 public:
  WrongAnimal();
  WrongAnimal(std::string type);
  WrongAnimal(WrongAnimal &src);
  virtual ~WrongAnimal();

  WrongAnimal &operator=(WrongAnimal &rhs);

  virtual void MakeSound() const;
  std::string GetType() const;

 protected:
  std::string type_;
};

#endif  // !WRONG_ANIMAL_H
