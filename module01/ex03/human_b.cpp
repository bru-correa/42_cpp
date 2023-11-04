#include "human_b.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL){};

void HumanB::Attack() {
  if (weapon_ == NULL) {
    std::cout << name_ << " is not holding any weapon!\n";
    return;
  }
  std::cout << name_ << " attacks with their " << weapon_->get_type() << "\n";
}

void HumanB::set_weapon(Weapon weapon) { weapon_ = &weapon; }
