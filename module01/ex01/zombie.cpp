#include "zombie.hpp"

Zombie::Zombie() : name_(){};

Zombie::Zombie(std::string name) : name_(name){};

void Zombie::Announce() {
  std::cout << name_ + ": " + "BraiiiiiiinnnzzzZ...\n";
}
