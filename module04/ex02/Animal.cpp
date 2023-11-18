#include "Animal.hpp"

#include <iostream>

#include "Colors.hpp"

Animal::Animal() : type_("Animal") {
  std::cout << "[ANIMAL] default constructor called\n";
};

Animal::Animal(std::string type) : type_(type) {
  std::cout << "[ANIMAL] parameter constructor called\n";
};

Animal::Animal(Animal &src) {
  std::cout << "[ANIMAL] copy constructor called\n";
  *this = src;
}

Animal::~Animal() { std::cout << "[ANIMAL] destructor called\n"; }

Animal &Animal::operator=(Animal &rhs) {
  if (this != &rhs) {
    type_ = rhs.type_;
  }
  return *this;
}

std::string Animal::GetType() const { return type_; }
