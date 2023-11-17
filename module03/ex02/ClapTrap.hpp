#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
 public:
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &src);
  ClapTrap &operator=(const ClapTrap &rhs);
  ~ClapTrap();

  void Attack(const std::string &target);
  void TakeDamage(unsigned int amount);
  void BeRepaired(unsigned int amount);

 protected:
  std::string name_;
  unsigned int hp_;
  unsigned int energy_;
  unsigned int attack_damage_;

  ClapTrap();

  bool CanAct();
};

#endif  // !CLAPTRAP_H
