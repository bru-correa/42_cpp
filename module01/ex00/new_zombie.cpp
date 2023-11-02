#include "zombie.hpp"

Zombie* NewZombie(std::string name) {
  Zombie* zombie = new Zombie(name);
  return zombie;
}
