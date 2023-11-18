#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <string>

class WrongAnimal {
 public:
  WrongAnimal();
  WrongAnimal(std::string type);
  WrongAnimal(WrongAnimal &src);
  ~WrongAnimal();

  WrongAnimal &operator=(WrongAnimal &rhs);

  void MakeSound() const;
  std::string GetType() const;

 protected:
  std::string type_;
};

#endif  // !WRONG_ANIMAL_H
