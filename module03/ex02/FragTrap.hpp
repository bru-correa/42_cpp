#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  FragTrap(std::string name);
  FragTrap(const FragTrap &src);
  FragTrap &operator=(const FragTrap &rhs);
  ~FragTrap();

  void HighFiveGuys();

 private:
  FragTrap();
};

#endif  // !FRAGTRAP_H
