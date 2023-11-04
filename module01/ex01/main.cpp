#include <iostream>

#include "zombie.hpp"

int main() {
  Zombie* horde = ZombieHorde(10, "ZugZug");
  for (int i = 0; i < 10; i++) {
    horde[0].Announce();
  }
  delete[] horde;
  return 0;
}
