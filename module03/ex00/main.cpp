#include <iostream>

#include "ClapTrap.hpp"

static void TestEnergy() {
  std::cout << "--------------- Testing Energy ---------------\n";
  ClapTrap immortal("Immortal");
  for (int i = 0; i < 10; i++) {
    immortal.BeRepaired(10);
  }
  immortal.BeRepaired(100);
  immortal.Attack("Weak Robot");
}

static void TestingCombat() {
  ClapTrap bot1("Marvin");
  bot1.Attack("Moulinette");
  bot1.TakeDamage(5);
  bot1.BeRepaired(5);
  bot1.TakeDamage(20);
  bot1.Attack("Moulinette");
}

int main() {
  TestEnergy();
  TestingCombat();
}
