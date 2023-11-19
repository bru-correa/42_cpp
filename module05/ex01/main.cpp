#include <iostream>

#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include "Form.hpp"

void TestValidForms() {
  std::cout << BLUE << "--------------- VALID FORMS TESTS --------------"
            << RESET << "\n";

  Bureaucrat mark("Mark", 100);
  std::cout << mark << "\n";

  std::cout << "[TEST] Bureaucrat has equal grade:\n";
  Form insurance("Insurance Policy", 100, 120);
  std::cout << insurance << "\n";
  mark.SignForm(insurance);
  std::cout << "------------------------------\n";

  std::cout << "[TEST] Form is already signed:\n";
  std::cout << insurance << "\n";
  mark.SignForm(insurance);
  std::cout << "------------------------------\n";

  std::cout << "[TEST] Bureaucrat has higher grade:\n";
  Form energy_bill("Energy Bill", 120, 125);
  std::cout << energy_bill << "\n";
  mark.SignForm(energy_bill);
  std::cout << "------------------------------\n";

  std::cout << "[TEST] Form copy constructor:\n";
  Form energy_bill2(energy_bill);
  std::cout << energy_bill2 << "\n";
  mark.SignForm(energy_bill2);
  std::cout << "------------------------------\n";

  std::cout << "[TEST] Bureaucrat has lower grade:\n";
  Form layoff("Massive layof authorization", 1, 10);
  std::cout << layoff << "\n";
  mark.SignForm(layoff);
  std::cout << "------------------------------\n";
}

void TestInvalidForms() {
  std::cout << BLUE << "--------------- INVALID FORMS TESTS --------------"
            << RESET << "\n";

  try {
    std::cout << "[TEST] Sign Grade too low:\n";
    Form insurance("Insurance", 151, 50);
    std::cout << GREEN << insurance << RESET << "\n";

  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << RESET << "\n";
  }

  try {
    std::cout << "[TEST] Sign Grade too high:\n";
    Form insurance("Insurance", 0, 50);
    std::cout << GREEN << insurance << RESET << "\n";

  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << RESET << "\n";
  }

  try {
    std::cout << "[TEST] Exec Grade too low:\n";
    Form insurance("Insurance", 50, 151);
    std::cout << GREEN << insurance << RESET << "\n";

  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << RESET << "\n";
  }

  try {
    std::cout << "[TEST] Exec Grade too high:\n";
    Form insurance("Insurance", 50, 0);
    std::cout << GREEN << insurance << RESET << "\n";

  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << RESET << "\n";
  }

  try {
    std::cout << "[TEST] Invalid Assign:\n";
    Form insurance("Insurance", 100, 100);
    Form energy_bill("Energy Bill", 50, 50);
    insurance = energy_bill;
    std::cout << GREEN << insurance << RESET << "\n";

  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << RESET << "\n";
  }
}

int main() {
  TestValidForms();
  TestInvalidForms();
}
