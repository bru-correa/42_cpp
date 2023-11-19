#ifndef FORM_H
#define FORM_H

#include <string>

class Bureaucrat;

class Form {
 public:
  Form(const std::string name, const int sign_grade, const int exec_grade);
  Form(Form &src);
  ~Form();

  Form &operator=(Form &rhs);

  void BeSigned(const Bureaucrat &bureaucrat);

  std::string get_name() const;
  int get_sign_grade() const;
  int get_exec_grade() const;
  bool get_is_signed() const;

 private:
  Form();
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

 private:
  class UnassignableException : public std::exception {
   public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif  // !FORM_H
