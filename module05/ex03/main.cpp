#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include "Intern.hpp"

void TestIntern() {
  std::cout << BLUE << "--------------- INTERN TESTS --------------" << RESET
            << "\n";
  try {
    std::cout << "[TEST] Presidential Pardon Form:\n";
    Intern intern;
    AForm *form = intern.MakeForm("PresidentialPardon", "Deckard");
    if (form == NULL) return;
    std::cout << *form;
    delete form;
    std::cout << BLUE "----------------------------------------" << RESET
              << "\n";
  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << RESET << "\n";
  }

  try {
    std::cout << "[TEST] Robotomy Request Form:\n";
    Intern intern;
    AForm *form = intern.MakeForm("RobotomyRequest", "Deckard");
    if (form == NULL) return;
    std::cout << *form;
    delete form;
    std::cout << BLUE "----------------------------------------" << RESET
              << "\n";
  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << RESET << "\n";
  }

  try {
    std::cout << "[TEST] Shrubbery Creation Form:\n";
    Intern intern;
    AForm *form = intern.MakeForm("ShrubberyCreation", "Deckard");
    if (form == NULL) return;
    std::cout << *form;
    delete form;
    std::cout << BLUE "----------------------------------------" << RESET
              << "\n";
  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << RESET << "\n";
  }

  try {
    std::cout << "[TEST] Invalid Form:\n";
    Intern intern;
    AForm *form = intern.MakeForm("InsurancePolicy", "Deckard");
    if (form == NULL) return;
    std::cout << *form;
    delete form;
    std::cout << BLUE "----------------------------------------" << RESET
              << "\n";
  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << RESET << "\n";
  }
}

int main() { TestIntern(); }
