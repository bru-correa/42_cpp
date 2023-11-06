#include <string>

#include "harl.hpp"

int main() {
  Harl harl;
  harl.Complain("DEBUG");
  harl.Complain("INFO");
  harl.Complain("WARNING");
  harl.Complain("ERROR");
  harl.Complain("INVALID");
}
