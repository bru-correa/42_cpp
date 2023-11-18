#include <iostream>

#include "Cat.hpp"
#include "Colors.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

static void TestAnimals() {
  std::cout << GREEN << "------------- ANIMALS TESTS -------------" << RESET
            << "\n";

  const Animal* animal = new Animal();
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();

  std::cout << dog->GetType() << "\n";
  std::cout << cat->GetType() << "\n";

  cat->MakeSound();
  dog->MakeSound();
  animal->MakeSound();

  delete animal;
  delete dog;
  delete cat;
}

static void TestWrongAnimals() {
  std::cout << GREEN << "------------- WRONG ANIMALS TESTS -------------"
            << RESET << "\n";

  const WrongAnimal* wrongAnimal = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << wrongAnimal->GetType() << "\n";
  std::cout << wrongCat->GetType() << "\n";

  wrongAnimal->MakeSound();
  wrongCat->MakeSound();

  delete wrongAnimal;
  delete wrongCat;
}

int main() {
  TestAnimals();
  TestWrongAnimals();
}
