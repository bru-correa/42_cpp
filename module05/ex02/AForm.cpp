#include "AForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"
#include "Colors.hpp"

/* CONSTRUCTORS */
AForm::AForm()
    : name_(""),
      is_signed_(false),
      sign_grade_(Bureaucrat::LOWEST_GRADE),
      exec_grade_(Bureaucrat::LOWEST_GRADE){};

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade)
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

AForm::AForm(AForm &src)
    : name_(src.name_),
      is_signed_(src.is_signed_),
      sign_grade_(src.sign_grade_),
      exec_grade_(src.exec_grade_){};

/* DESTRUCTORS */
AForm::~AForm(){};

/* OVERLOADS */
AForm &AForm::operator=(AForm &rhs) {
  if (this != &rhs) throw UnassignableException();
  return *this;
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs) {
  out << "📄" << rhs.get_name() << ":\n";
  out << "\t signed: " << (rhs.get_is_signed() ? "yes" : "no") << "\n";
  out << "\t required grade to sign: " << rhs.get_sign_grade() << "\n";
  out << "\t required grade to exec: " << rhs.get_exec_grade() << "\n";
  return out;
}

/* METHODS */
void AForm::BeSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.get_grade() <= sign_grade_) {
    is_signed_ = true;
  }
}

void AForm::Execute(const Bureaucrat &executor) const {
  if (executor.get_grade() > exec_grade_)
    throw LowGradeExecutor();
  else if (is_signed_ == false)
    throw FormNotSigned();
  std::cout << GREEN << executor.get_name() << " executed 📄[" << name_ << "]"
            << RESET << "\n";
  Action();
}

/* ACESSORS */
std::string AForm::get_name() const { return name_; }
int AForm::get_sign_grade() const { return sign_grade_; }
int AForm::get_exec_grade() const { return exec_grade_; }
bool AForm::get_is_signed() const { return is_signed_; }

/* EXCEPTIONS */
const char *AForm::GradeTooHighException::what() const throw() {
  return "Form grade's is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Form grade's is too low";
}

const char *AForm::FormNotSigned::what() const throw() {
  return "Can't execute a form that is not signed yet";
}

const char *AForm::LowGradeExecutor::what() const throw() {
  return "Executor grade is too low";
}

const char *AForm::UnassignableException::what() const throw() {
  return "Form is unassignable";
}
