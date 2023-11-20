#include <algorithm>
#include <iostream>
#include <vector>

#include "easy_find.hpp"

int main() {
  std::cout << "--------------- EASY FIND TEST ---------------\n";
  int array[7] = {6, 5, 4, 3, 2, 1, 0};

  std::vector<int> container(array, array + sizeof(array) / sizeof(int));
  std::vector<int>::iterator it;

  std::cout << "Creating Container with size 7" << '\n';
  for (it = container.begin(); it != container.end(); it++) {
    std::cout << *it << ' ';
  }
  std::cout << "\n";

  std::cout << "Array[9]: ";
  try {
    std::cout << *EasyFind(container, 9);
  } catch (const std::exception &e) {
    std::cerr << e.what();
  }

  std::cout << "Array[2]: ";
  try {
    std::cout << *EasyFind(container, 2);
  } catch (const std::exception &e) {
    std::cerr << e.what();
  }
  std::cout << "\n";
  return (0);
}
