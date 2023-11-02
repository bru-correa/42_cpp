#include "zombie.hpp"

void RandomChump(std::string name) {
  Zombie zombie(name);
  zombie.announce();
}
