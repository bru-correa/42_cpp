#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "weapon.hpp"

class HumanA {
 public:
  HumanA(std::string name, Weapon& weapon);
  void Attack();
  void set_weapon(const Weapon& weapon);

 private:
  std::string name_;
  Weapon& weapon_;
};

#endif  // !HUMAN_A_HPP
