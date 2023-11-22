#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Invalid arguments\n";
    return 1;
  }
  BitcoinExchange btc(std::string("./data.csv"));
  btc.ParseFile(std::string(argv[1]));
}
