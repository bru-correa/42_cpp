#include <iostream>

#include "ScavTrap.hpp"

static void TestingCombat() {
  ScavTrap base_marvin("Marvin");
  ScavTrap marvin = base_marvin;
  marvin.Attack("Moulinette");
  marvin.TakeDamage(50);
  marvin.BeRepaired(50);
  marvin.TakeDamage(120);
  marvin.Attack("Moulinette");
}

static void TestGuardKeeper() {
  ScavTrap hodoor("Hodoor");
  hodoor.GuardGate();
  hodoor.GuardGate();
}

int main() {
  TestingCombat();
  TestGuardKeeper();
}
