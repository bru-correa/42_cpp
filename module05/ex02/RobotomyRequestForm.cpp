#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Colors.hpp"

/* CONSTRUCTORS */
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target_(""){};

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target){};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src)
    : AForm(src), target_(src.target_){};

/* DESTRUCTORS */
RobotomyRequestForm::~RobotomyRequestForm(){};

/* OVERLOADS */
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &rhs) {
  if (this != &rhs) {
    throw UnassignableException();
  }
  return *this;
}

/* METHODS */
void RobotomyRequestForm::Action() const {
  std::srand(std::time(NULL));
  const int random = std::rand();
  if (random % 2) {
    std::cout << GREEN << "*DRILLING NOISES*\n";
    std::cout << target_ << " has been robotomized successfully!" << RESET
              << "\n";
  } else {
    std::cout << RED << "*DRILLING NOISES*\n";
    std::cout << target_ << " failed to be robotomized!" << RESET << "\n";
  }
}
