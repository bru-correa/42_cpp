#include "Intern.hpp"

#include <iostream>

#include "Colors.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string Intern::form_types[3] = {
    "PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};

/* CONSTRUCTORS */
Intern::Intern(){};

Intern::Intern(Intern &src) { *this = src; }

Intern::~Intern(){};

/* OVERLOADS */
Intern &Intern::operator=(Intern &rhs) {
  if (this == &rhs) return *this;
  return *this;
}

AForm *Intern::MakePardon(const std::string target) {
  AForm *pardon_form = new PresidentialPardonForm(target);
  return pardon_form;
};

AForm *Intern::MakeRobotomy(const std::string target) {
  AForm *robotomy_form = new RobotomyRequestForm(target);
  return robotomy_form;
};

AForm *Intern::MakeShrubbery(const std::string target) {
  AForm *shrubbery_form = new ShrubberyCreationForm(target);
  return shrubbery_form;
};

/* METHODS */
AForm *Intern::MakeForm(const std::string name, const std::string target) {
  typedef AForm *(Intern::*FormFunctions)(const std::string target);
  FormFunctions form_functions[3] = {&Intern::MakePardon, &Intern::MakeRobotomy,
                                     &Intern::MakeShrubbery};
  for (int i = 0; i < 3; i++) {
    if (name == form_types[i]) {
      return (this->*(form_functions[i]))(target);
    }
  }
  throw InvalidForm();
  return NULL;
}

/* EXCEPTIONS */
const char *Intern::InvalidForm::what() const throw() {
  return "There is no form with this name";
}
