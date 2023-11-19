#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include <string>

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm(const std::string target);
  RobotomyRequestForm(RobotomyRequestForm &src);
  virtual ~RobotomyRequestForm();

  RobotomyRequestForm &operator=(RobotomyRequestForm &rhs);

  virtual void Action() const;

 private:
  RobotomyRequestForm();
  const std::string target_;
};

#endif  // !ROBOTOMY_REQUEST_FORM_H
