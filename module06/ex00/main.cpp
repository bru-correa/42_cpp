#include <string>

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Invalid Parameters\n";
    return 1;
  }
  std::string input(argv[1]);
  ScalarConverter::Convert(input);
}
