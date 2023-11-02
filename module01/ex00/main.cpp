#include <iostream>

#include "zombie.hpp"

int main() {
  std::cout << "THE ZOMBIES ARE COMING!!!\n";
  Zombie zombieGilberto("GRomero");
  zombieGilberto.announce();
  RandomChump("MJThriller");
  Zombie* zombieBrainEater = NewZombie("BrainEater12");
  zombieBrainEater->announce();
  delete zombieBrainEater;
  return 0;
}
