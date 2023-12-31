#include <iostream>

#include "Cat.hpp"
#include "Colors.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

static void TestAnimals() {
  std::cout << GREEN << "------------- ANIMALS TESTS -------------" << RESET
            << "\n";

  const Animal* dog = new Dog();
  const Animal* cat = new Cat();

  std::cout << dog->GetType() << "\n";
  std::cout << cat->GetType() << "\n";

  cat->MakeSound();
  dog->MakeSound();

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

static void TestAnimalFactory() {
  std::cout << GREEN << "------------- ANIMAL FACTORY TEST -------------"
            << RESET << "\n";
  Animal* animals[10];
  for (int i = 0; i < 5; i++) {
    animals[i] = new Cat();
  }
  for (int i = 5; i < 10; i++) {
    animals[i] = new Dog();
  }
  for (int i = 0; i < 10; i++) {
    animals[i]->MakeSound();
    delete animals[i];
  }
}

static void TestDeepCopy() {
  std::cout << GREEN << "------------- DEEP COPY TEST -------------" << RESET
            << "\n";
  Dog dog;
  { Dog temp = dog; }
  std::cout << GREEN << "------------------------------------------" << RESET
            << "\n";
  Cat cat;
  { Cat temp = cat; }
  std::cout << GREEN << "------------------------------------------" << RESET
            << "\n";
}

int main() {
  TestAnimals();
  TestWrongAnimals();
  TestAnimalFactory();
  TestDeepCopy();
}
