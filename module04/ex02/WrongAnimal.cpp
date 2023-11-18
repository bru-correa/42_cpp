#include "WrongAnimal.hpp"

#include <iostream>

#include "Colors.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
  std::cout << "[WRONG_ANIMAL] default constructor called\n";
};

WrongAnimal::WrongAnimal(std::string type) : type_(type) {
  std::cout << "[WRONG_ANIMAL] parameter constructor called\n";
};

WrongAnimal::WrongAnimal(WrongAnimal &src) {
  std::cout << "[WRONG_ANIMAL] copy constructor called\n";
  *this = src;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "[WRONG_ANIMAL] destructor called\n";
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &rhs) {
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

void WrongAnimal::MakeSound() const {
  std::cout << RED << "Wrong Animal: I'm definitely an animal" << RESET << "\n";
}

std::string WrongAnimal::GetType() const { return type_; }
