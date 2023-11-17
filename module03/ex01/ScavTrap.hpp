#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &src);
  ScavTrap &operator=(const ScavTrap &rhs);
  ~ScavTrap();

  void Attack(const std::string &target);
  void GuardGate();

 private:
  bool is_guarding_gate;
  ScavTrap();
};

#endif  // !SCAVTRAP_H
