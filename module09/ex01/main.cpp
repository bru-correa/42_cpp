#include <iostream>

#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Invalid Arguments\n";
    return 1;
  }
  try {
    RPN rpn;
    rpn.ExecuteOperation(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
}
