#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), is_guarding_gate(false) {
  std::cout << "ScavTrap Default constructor called\n";
  set_hp(100);
  set_energy(50);
  set_attack_damage(20);
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), is_guarding_gate(false) {
  std::cout << "ScavTrap Parameter constructor called\n";
  set_hp(100);
  set_energy(50);
  set_attack_damage(20);
};

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor called\n"; }

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
  is_guarding_gate = src.is_guarding_gate;
  std::cout << "ScavTrap Copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
  if (this != &rhs) {
    set_name(rhs.get_name());
    set_hp(rhs.get_hp());
    set_energy(rhs.get_energy());
    set_attack_damage(rhs.get_attack_damage());
    is_guarding_gate = rhs.is_guarding_gate;
  }
  return *this;
}

void ScavTrap::Attack(const std::string &target) {
  if (CanAct() == false) return;
  set_energy(get_energy() - 1);
  std::cout << "ScavTrap " << get_name() << " attacks " << target << " causing "
            << get_attack_damage() << " points of damage!\n";
}

void ScavTrap::GuardGate() {
  is_guarding_gate = !is_guarding_gate;
  if (is_guarding_gate == true) {
    std::cout << get_name() << " is now is in Gate Keeper Mode\n";
  } else {
    std::cout << get_name() << " is now in Normal Mode\n";
  }
}
