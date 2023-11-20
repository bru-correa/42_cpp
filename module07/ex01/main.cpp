#include <iostream>

#include "iter.hpp"

template <typename T>
void increment(T &element) {
  element++;
}

int main() {
  std::cout << "------------------ INT TEST ------------------\n";

  int int_array[] = {0, 1, 2, 3, 4, 5};

  std::cout << "Before increment:\n";
  for (int i = 0; i < 5; i++) std::cout << int_array[i] << " ";
  std::cout << "\n";

  std::cout << "After increment:\n";
  ::iter(int_array, 5, ::increment);
  for (int i = 0; i < 5; i++) std::cout << int_array[i] << " ";
  std::cout << "\n";

  std::cout << "------------------ CHAR TEST ------------------\n";

  char char_array[] = {'a', 'b', 'c', 'd', 'e'};

  std::cout << "Before increment:\n";
  for (int i = 0; i < 5; i++) std::cout << char_array[i] << " ";
  std::cout << "\n";

  std::cout << "After increment:\n";
  ::iter(char_array, 5, ::increment);
  for (int i = 0; i < 5; i++) std::cout << char_array[i] << " ";
  std::cout << "\n";
}
