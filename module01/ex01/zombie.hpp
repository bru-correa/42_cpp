#ifndef ZOMBIE_H
#define ZOMBIE_H
#endif  // !ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
 private:
  std::string name_;

 public:
  Zombie();
  Zombie(std::string name);

  void Announce();
};

Zombie* ZombieHorde(int N, std::string name);
