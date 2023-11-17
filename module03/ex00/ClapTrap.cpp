#include "ClapTrap.hpp"

#include <iostream>

// Private
ClapTrap::ClapTrap() : name_(""), hp_(10), energy_(10), attack_damage_(0) {
  std::cout << "ClapTrap Default constructor called\n";
};

// Public
ClapTrap::ClapTrap(std::string name)
    : name_(name), hp_(10), energy_(10), attack_damage_(0) {
  std::cout << "ClapTrap Parameter constructor called\n";
};

ClapTrap::ClapTrap(ClapTrap const &src) { *this = src; }

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
  if (this != &rhs) {
    this->name_ = rhs.name_;
    this->hp_ = rhs.hp_;
    this->energy_ = rhs.energy_;
    this->attack_damage_ = rhs.attack_damage_;
  }
  return *this;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap Destructor called\n"; };

bool ClapTrap::CanAct() {
  if (hp_ == 0) {
    std::cout << "ClapTrap " << name_ << " is knocked out!\n";
    return false;
  } else if (energy_ == 0) {
    std::cout << "ClapTrap " << name_ << " is out of energy points!\n";
    return false;
  }
  return true;
}

void ClapTrap::Attack(const std::string &target) {
  if (CanAct() == false) return;
  energy_--;
  std::cout << "ClapTrap " << name_ << " attacks " << target << " causing "
            << attack_damage_ << " points of damage!\n";
}

void ClapTrap::TakeDamage(unsigned int amount) {
  amount > hp_ ? hp_ = 0 : hp_ -= amount;
  std::cout << "ClapTrap " << name_ << " takes " << amount
            << " points of damage\n";
}

void ClapTrap::BeRepaired(unsigned int amount) {
  if (CanAct() == false) return;
  hp_ += amount;
  energy_--;
  std::cout << "ClapTrap " << name_ << " repairs itself and heals " << amount
            << " health points!\n";
}
