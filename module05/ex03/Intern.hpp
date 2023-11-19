#ifndef INTERN_H
#define INTERN_H

#include <string>

#include "AForm.hpp"

class Intern {
 public:
  Intern();
  Intern(Intern &src);
  ~Intern();

  Intern &operator=(Intern &rhs);

  AForm *MakeForm(const std::string name, const std::string target);

 private:
  static const std::string form_types[3];
  AForm *MakePardon(const std::string target);
  AForm *MakeRobotomy(const std::string target);
  AForm *MakeShrubbery(const std::string target);

  /* EXCEPTIONS */
 public:
  class InvalidForm : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

#endif  // !INTERN_H
