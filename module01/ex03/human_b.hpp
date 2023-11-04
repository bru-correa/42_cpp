#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "weapon.hpp"

class HumanB {
 public:
  HumanB(std::string name);
  void Attack();
  void set_weapon(const Weapon weapon);

 private:
  std::string name_;
  Weapon* weapon_;
};

#endif  // !HUMAN_B_HPP
