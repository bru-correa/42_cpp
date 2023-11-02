#include "zombie.hpp"

Zombie::Zombie() : name_(){};

Zombie::Zombie(std::string name) : name_(name){};

Zombie::~Zombie() { std::cout << "Destroying " << name_ << "\n"; }

void Zombie::announce() {
  std::cout << name_ + ": " + "BraiiiiiiinnnzzzZ...\n";
}
