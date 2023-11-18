#include "WrongCat.hpp"

#include <iostream>

#include "Colors.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  std::cout << "[WRONG_CAT] default constructor called\n";
  type_ = "WrongCat";
};

WrongCat::WrongCat(WrongCat &src) : WrongAnimal(src) {
  std::cout << "[WRONG_CAT] copy constructor called\n";
  *this = src;
}

WrongCat::~WrongCat() { std::cout << "[WRONG_CAT] destructor called\n"; }

WrongCat &WrongCat::operator=(WrongCat &rhs) {
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

void WrongCat::MakeSound() const {
  std::cout << RED << "Wrong Cat: OOOPS! I mean........meow?" << RESET << "\n";
}
