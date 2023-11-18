#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
 public:
  Animal();
  Animal(std::string type);
  Animal(Animal &src);
  virtual ~Animal();

  Animal &operator=(Animal &rhs);

  virtual void MakeSound() const = 0;
  std::string GetType() const;

 protected:
  std::string type_;
};

#endif  // !ANIMAL_H
