#include "Form.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

/* CONSTRUCTORS */
Form::Form()
    : name_(""),
      is_signed_(false),
      sign_grade_(Bureaucrat::LOWEST_GRADE),
      exec_grade_(Bureaucrat::LOWEST_GRADE){};

Form::Form(const std::string name, const int sign_grade, const int exec_grade)
    : name_(name),
      is_signed_(false),
      sign_grade_(sign_grade),
      exec_grade_(exec_grade) {
  if (sign_grade_ > Bureaucrat::LOWEST_GRADE ||
      exec_grade_ > Bureaucrat::LOWEST_GRADE) {
    throw GradeTooLowException();
  } else if (sign_grade_ < Bureaucrat::HIGHEST_GRADE ||
             exec_grade_ < Bureaucrat::HIGHEST_GRADE) {
    throw GradeTooHighException();
  }
};

Form::Form(Form &src)
    : name_(src.name_),
      is_signed_(src.is_signed_),
      sign_grade_(src.sign_grade_),
      exec_grade_(src.exec_grade_){};

/* DESTRUCTORS */
Form::~Form(){};

/* OVERLOADS */
Form &Form::operator=(Form &rhs) {
  if (this != &rhs) throw UnassignableException();
  return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &rhs) {
  out << "📄" << rhs.get_name() << ":\n";
  out << "\t signed: " << (rhs.get_is_signed() ? "yes" : "no") << "\n";
  out << "\t required grade to sign: " << rhs.get_sign_grade() << "\n";
  out << "\t required grade to exec: " << rhs.get_exec_grade() << "\n";
  return out;
}

/* METHODS */
void Form::BeSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.get_grade() <= sign_grade_) {
    is_signed_ = true;
  }
}

/* ACESSORS */
std::string Form::get_name() const { return name_; }
int Form::get_sign_grade() const { return sign_grade_; }
int Form::get_exec_grade() const { return exec_grade_; }
bool Form::get_is_signed() const { return is_signed_; }

/* EXCEPTIONS */
const char *Form::GradeTooHighException::what() const throw() {
  return "Form grade's is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Form grade's is too low";
}

const char *Form::UnassignableException::what() const throw() {
  return "Form is unassignable";
}
