#include <iostream>
#include <string>

int main() {
  std::string brain("HI THIS IS BRAIN");
  std::string* stringPTR = &brain;
  std::string& stringREF = brain;

  std::cout << "Address of brain: " << &brain << "\n";
  std::cout << "Address of stringPTR: " << stringPTR << "\n";
  std::cout << "Address of stringREF: " << &stringREF << "\n";
  std::cout << "------------------------------\n";
  std::cout << "Value of brain: " << brain << "\n";
  std::cout << "Value of stringPTR: " << *stringPTR << "\n";
  std::cout << "Value of stringREF: " << stringREF << "\n";
}
