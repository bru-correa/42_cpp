#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), is_guarding_gate(false) {
  std::cout << "ScavTrap Default constructor called\n";
  hp_ = 100;
  energy_ = 50;
  attack_damage_ = 20;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), is_guarding_gate(false) {
  std::cout << "ScavTrap Parameter constructor called\n";
  hp_ = 100;
  energy_ = 50;
  attack_damage_ = 20;
};

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor called\n"; }

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
  is_guarding_gate = src.is_guarding_gate;
  std::cout << "ScavTrap Copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
  if (this != &rhs) {
    name_ = rhs.name_;
    hp_ = rhs.hp_;
    energy_ = rhs.energy_;
    attack_damage_ = rhs.attack_damage_;
    is_guarding_gate = rhs.is_guarding_gate;
  }
  return *this;
}

void ScavTrap::Attack(const std::string &target) {
  if (CanAct() == false) return;
  energy_--;
  std::cout << name_ << " shoots " << target << " causing " << attack_damage_
            << " points of damage!\n";
}

void ScavTrap::GuardGate() {
  is_guarding_gate = !is_guarding_gate;
  if (is_guarding_gate == true) {
    std::cout << name_ << " is now is in Gate Keeper Mode\n";
  } else {
    std::cout << name_ << " is now in Normal Mode\n";
  }
}
