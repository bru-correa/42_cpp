#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap Default constructor called\n";
  hp_ = 100;
  energy_ = 100;
  attack_damage_ = 30;
};

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap Parameter constructor called\n";
  hp_ = 100;
  energy_ = 100;
  attack_damage_ = 30;
};

FragTrap::~FragTrap() { std::cout << "FragTrap Destructor called\n"; }

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
  std::cout << "FragTrap Copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
  if (this != &rhs) {
    name_ = rhs.name_;
    hp_ = rhs.hp_;
    energy_ = rhs.energy_;
    attack_damage_ = rhs.attack_damage_;
  }
  return *this;
}

void FragTrap::HighFiveGuys() {
  std::cout << name_ << " is jumping and happily requesting for a HIGH FIVE!\n";
}
