#include <iostream>

#include "Phonebook.hpp"

void print_header() {
  std::cout << "\033[1;34m";
  std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
  std::cout << " Phone Book ";
  std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
  std::cout << "\033[0m\n";
}

void repl(Phonebook phonebook) {
  print_header();
  std::string input = "";
  while (input != "EXIT") {
    std::cout << "Enter a command: ";
    std::getline(std::cin, input);
    if (input == "ADD")
      phonebook.Add();
    else if (input == "SEARCH")
      phonebook.Search();
    else if (input == "EXIT") {
      break;
    } else {
      std::cout
          << "Invalid command! The only valid commands are: ADD SEARCH EXIT\n";
    }
  }
}

int main(void) {
  Phonebook phonebook;
  repl(phonebook);
  return 0;
}
