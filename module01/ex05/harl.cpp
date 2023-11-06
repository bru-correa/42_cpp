#include "harl.hpp"

#include <iostream>

void Harl::Complain(std::string level) {
  typedef void (Harl::*ComplainType)();
  ComplainType complain_type[4] = {&Harl::Debug, &Harl::Info, &Harl::Warning,
                                   &Harl::Error};
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (int i = 0; i < 4; i++) {
    if (level == levels[i]) {
      (this->*(complain_type[i]))();
      return;
    }
  }
  std::cout << "Invalid level\n";
}

void Harl::Debug() { std::cout << "DEBUG level message\n"; }

void Harl::Info() { std::cout << "INFO level message\n"; }

void Harl::Warning() { std::cout << "WARNING level message\n"; }

void Harl::Error() { std::cout << "ERROR level message\n"; }
