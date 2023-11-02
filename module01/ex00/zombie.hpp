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
  ~Zombie();
  Zombie(std::string name);
  void announce();
};

Zombie* NewZombie(std::string name);

void RandomChump(std::string name);
