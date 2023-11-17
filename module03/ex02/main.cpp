#include <iostream>

#include "FragTrap.hpp"

static void TestingCombat() {
  FragTrap base_marvin("Marvin");
  FragTrap marvin = base_marvin;
  marvin.Attack("Moulinette");
  marvin.TakeDamage(50);
  marvin.BeRepaired(50);
  marvin.TakeDamage(120);
  marvin.Attack("Moulinette");
}

static void TestHighFive() {
  FragTrap norminette("Norminette");
  norminette.HighFiveGuys();
}

int main() {
  TestingCombat();
  TestHighFive();
}
