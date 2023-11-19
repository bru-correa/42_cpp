#include "PresidentialPardonForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"
#include "Colors.hpp"

/* CONSTRUCTORS */
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target_(""){};

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target_(target){};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src)
    : AForm(src), target_(src.target_){};

/* DESTRUCTORS */
PresidentialPardonForm::~PresidentialPardonForm(){};

/* OVERLOADS */
PresidentialPardonForm &PresidentialPardonForm::operator=(
    PresidentialPardonForm &rhs) {
  if (this != &rhs) {
    throw UnassignableException();
  }
  return *this;
}

/* METHODS */
void PresidentialPardonForm::Action() const {
  std::cout << GREEN << target_ << " is pardoned by Zaphod Beeblebrox" << RESET
            << "\n";
}
