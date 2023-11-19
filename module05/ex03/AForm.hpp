#ifndef AFORM_H
#define AFORM_H

#include <string>

class Bureaucrat;

class AForm {
 public:
  AForm(const std::string name, const int sign_grade, const int exec_grade);
  AForm(AForm &src);
  virtual ~AForm();

  AForm &operator=(AForm &rhs);

  void Execute(const Bureaucrat &executor) const;
  void BeSigned(const Bureaucrat &bureaucrat);
  virtual void Action() const = 0;

  std::string get_name() const;
  int get_sign_grade() const;
  int get_exec_grade() const;
  bool get_is_signed() const;

 private:
  AForm();
  const std::string name_;
  bool is_signed_;
  const int sign_grade_;
  const int exec_grade_;

  /* EXCEPTIONS */
 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
  class FormNotSigned : public std::exception {
   public:
    virtual const char *what() const throw();
  };
  class LowGradeExecutor : public std::exception {
   public:
    virtual const char *what() const throw();
  };
  class UnassignableException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const AForm &rhs);

#endif  // !AFORM_H
