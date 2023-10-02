#include "SetColor.hpp"

std::string SetBlueColor(std::string string) {
  std::string blue_colored_str = "\033[1;34m" + string + "\033[0m";
  return blue_colored_str;
}

std::string SetRedColor(std::string string) {
  std::string red_colored_str = "\033[1;31m" + string + "\033[0m";
  return red_colored_str;
}
