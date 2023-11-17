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
  ClapTrap();

  std::string get_name() const;
  unsigned int get_hp() const;
  unsigned int get_energy() const;
  unsigned int get_attack_damage() const;

  void set_name(std::string);
  void set_hp(unsigned int hp);
  void set_energy(unsigned int energy);
  void set_attack_damage(unsigned int attack_damage);

  bool CanAct();

 private:
  std::string name_;
  unsigned int hp_;
  unsigned int energy_;
  unsigned int attack_damage_;
};

#endif  // !CLAPTRAP_H
