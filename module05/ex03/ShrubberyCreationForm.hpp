#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include <string>

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm(const std::string target);
  ShrubberyCreationForm(ShrubberyCreationForm &src);
  virtual ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=(ShrubberyCreationForm &rhs);

  virtual void Action() const;

 private:
  ShrubberyCreationForm();
  const std::string target_;
};

#endif  // !SHRUBBERY_CREATION_FORM_H
