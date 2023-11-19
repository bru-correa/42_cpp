#include "Bureaucrat.hpp"

#include <iostream>

/* CONSTRUCTORS */
Bureaucrat::Bureaucrat() : name_(""), grade_(LOWEST_GRADE){};

Bureaucrat::Bureaucrat(const std::string name, const int grade)
    : name_(name), grade_(grade) {
  if (grade > LOWEST_GRADE) {
    throw GradeTooLowException();
  } else if (grade < HIGHEST_GRADE) {
    throw GradeTooHighException();
  }
};

Bureaucrat::Bureaucrat(Bureaucrat &src)
    : name_(src.name_), grade_(src.grade_){};

/* DESTRUCTORS */
Bureaucrat::~Bureaucrat(){};

/* OVERLOADS */
Bureaucrat &Bureaucrat::operator=(Bureaucrat &rhs) {
  if (this != &rhs) throw UnassignableException();
  return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
  out << rhs.get_name() << ", bureaucrat grade " << rhs.get_grade() << ".";
  return out;
}

/* METHODS */
void Bureaucrat::IncrementGrade() {
  if (grade_ - 1 < HIGHEST_GRADE) throw GradeTooHighException();
  grade_--;
}

void Bureaucrat::DecrementGrade() {
  if (grade_ + 1 > LOWEST_GRADE) throw GradeTooLowException();
  grade_++;
}

/* ACESSORS */
std::string Bureaucrat::get_name() const { return name_; }
int Bureaucrat::get_grade() const { return grade_; }

/* EXCEPTIONS */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaucrat grade's is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat grade's is too low";
}

const char *Bureaucrat::UnassignableException::what() const throw() {
  return "Bureaucrat is unassignable";
}
