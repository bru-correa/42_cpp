#include "Brain.hpp"

#include <iostream>

Brain::Brain() { std::cout << "[BRAIN] Default constructor is called\n"; }

Brain::Brain(Brain &src) {
  std::cout << "[BRAIN] Copy constructor called\n";
  *this = src;
}

Brain::~Brain() { std::cout << "[BRAIN] Destructor is called\n"; }

Brain &Brain::operator=(Brain &rhs) {
  if (this != &rhs) {
    for (int i = 0; i < 100; i++) {
      ideas[i] = rhs.ideas[i];
    }
  }
  return *this;
}
