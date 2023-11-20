#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate() {
  std::srand(std::time(NULL));
  int random = std::rand() % 3;
  if (random == 0) {
    std::cout << "Generated Class A\n";
    return new A;
  } else if (random == 1) {
    std::cout << "Generated Class B\n";
    return new B;
  } else if (random == 2) {
    std::cout << "Generated Class C\n";
    return new C;
  }
  return NULL;
}

void identify(Base *p) {
  std::cout << "Object is of type ";
  if (dynamic_cast<A *>(p))
    std::cout << "A\n";
  else if (dynamic_cast<B *>(p))
    std::cout << "B\n";
  else if (dynamic_cast<C *>(p))
    std::cout << "C\n";
  else
    std::cout << "Unknown\n";
}

void identify(Base &p) {
  std::cout << "Object is of type ";
  try {
    if (dynamic_cast<A *>(&p)) std::cout << "A\n";
  } catch (const std::exception &e) {
  }
  try {
    if (dynamic_cast<B *>(&p)) std::cout << "B\n";
  } catch (const std::exception &e) {
  }
  try {
    if (dynamic_cast<C *>(&p)) std::cout << "C\n";
  } catch (const std::exception &e) {
  }
}

int main() {
  std::cout << "--------------- IDENTIFY TEST ---------------\n";
  Base *ptr = generate();
  std::cout << "Check by address: ";
  identify(ptr);
  std::cout << "Check by reference: ";
  identify(*ptr);
  delete ptr;
}
