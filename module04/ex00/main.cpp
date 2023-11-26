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

  const WrongAnimal* wrong_animal = new WrongAnimal();
  const WrongAnimal* wrong_animal_cat = new WrongCat();
  const WrongCat* wrong_cat = new WrongCat();

  std::cout << wrong_animal->GetType() << "\n";
  std::cout << wrong_animal_cat->GetType() << "\n";
  std::cout << wrong_cat->GetType() << "\n";

  wrong_animal->MakeSound();
  wrong_animal_cat->MakeSound();
  wrong_cat->MakeSound();

  delete wrong_animal;
  delete wrong_animal_cat;
  delete wrong_cat;
}

int main() {
  TestAnimals();
  TestWrongAnimals();
}
