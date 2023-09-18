#include <iostream>

#include "src/Contact.hpp"

int main(void) {
  Contact contact("Nome", "Sobrenome", "Apelido", "000000000", "Segredo");
  std::cout << "Welcome to the 80s kid\n";
  return 0;
}
