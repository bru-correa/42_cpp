#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include <string>

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm(const std::string target);
  PresidentialPardonForm(PresidentialPardonForm &src);
  virtual ~PresidentialPardonForm();

  PresidentialPardonForm &operator=(PresidentialPardonForm &rhs);

  virtual void Action() const;

 private:
  PresidentialPardonForm();
  const std::string target_;
};

#endif  // !PRESIDENTIAL_PARDON_FORM_H
