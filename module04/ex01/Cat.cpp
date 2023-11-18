#include "Cat.hpp"

#include <iostream>

#include "Colors.hpp"

Cat::Cat() : Animal() {
  std::cout << "[CAT] default constructor called\n";
  type_ = "Cat";
  brain_ = new Brain();
};

Cat::Cat(Cat &src) : Animal(src) {
  std::cout << "[CAT] copy constructor called\n";
  *this = src;
}

Cat::~Cat() {
  std::cout << "[CAT] destructor called\n";
  delete brain_;
}

Cat &Cat::operator=(Cat &rhs) {
  if (this != &rhs) {
    type_ = rhs.type_;
    brain_ = new Brain(*rhs.brain_);
  }
  return *this;
}

void Cat::MakeSound() const {
  std::cout << RED << "Cat: MEEEEEOOOOOW" << RESET << "\n";
}
