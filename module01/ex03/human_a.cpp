#include "human_a.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon)
    : name_(name), weapon_(weapon){};

void HumanA::Attack() {
  std::cout << name_ << " attacks with their " << weapon_.get_type() << "\n";
}

void HumanA::set_weapon(const Weapon& weapon) { weapon_ = weapon; }
