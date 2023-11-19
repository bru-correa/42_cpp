#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>

class Bureaucrat {
 public:
  static const int LOWEST_GRADE = 150;
  static const int HIGHEST_GRADE = 1;

  Bureaucrat(const std::string name, const int grade);
  Bureaucrat(Bureaucrat &src);
  ~Bureaucrat();

  Bureaucrat &operator=(Bureaucrat &rhs);

  void IncrementGrade();
  void DecrementGrade();

  std::string get_name() const;
  int get_grade() const;

 private:
  Bureaucrat();
  const std::string name_;
  int grade_;

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif  // !BUREAUCRAT_H
