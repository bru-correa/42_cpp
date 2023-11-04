#include <iostream>

#include "human_a.hpp"
#include "human_b.hpp"

int main() {
  Weapon melee_weapon = Weapon("Dragon Scimitar");

  HumanA bob("Bob", melee_weapon);
  bob.Attack();
  melee_weapon.set_type("Morning Star");
  bob.Attack();
  std::cout << "-----------------------------------\n";
  Weapon ranged_weapon = Weapon("Magic Shortbow");
  HumanB jim("Jim");
  jim.Attack();
  jim.set_weapon(ranged_weapon);
  jim.Attack();
  ranged_weapon.set_type("Rune Crossbow");
  jim.Attack();
}
