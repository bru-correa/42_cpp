#include "Dog.hpp"

#include <iostream>

#include "Colors.hpp"

Dog::Dog() : Animal() {
  std::cout << "[DOG] default constructor called\n";
  type_ = "Dog";
};

Dog::Dog(Dog &src) : Animal(src) {
  std::cout << "[DOG] copy constructor called\n";
  *this = src;
}

Dog::~Dog() { std::cout << "[DOG] destructor called\n"; }

Dog &Dog::operator=(Dog &rhs) {
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

void Dog::MakeSound() const {
  std::cout << RED << "Dog: WOOF WOF WOOOOF" << RESET << "\n";
}
