#include <iostream>

#include "zombie.hpp"

int main() {
  std::cout << "THE ZOMBIES ARE COMING!!!\n";
  Zombie zombieGilberto("GRomero");
  zombieGilberto.Announce();
  RandomChump("MJThriller");
  Zombie* zombieBrainEater = NewZombie("BrainEater12");
  zombieBrainEater->Announce();
  delete zombieBrainEater;
  return 0;
}
