#include "ScalarConverter.hpp"

#include <limits.h>

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

const std::string ScalarConverter::pseudo_literals_[3] = {"-inf", "+inf",
                                                          "nan"};
char ScalarConverter::char_ = 0;
long ScalarConverter::int_ = 0;
float ScalarConverter::float_ = 0;
double ScalarConverter::double_ = 0;
bool ScalarConverter::is_pseudo_ = 0;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs) {
  if (this != &rhs) {
    char_ = rhs.char_;
    int_ = rhs.int_;
    float_ = rhs.float_;
    double_ = rhs.double_;
  }
  return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScalarConverter::Convert(const std::string& literal) {
  if (literal.empty()) {
    std::cout << "Invalid Argument\n";
    return;
  }
  if (IsPseudo(literal))
    is_pseudo_ = true;
  else if (IsChar(literal))
    ConvertFromChar(literal);
  else if (IsInt(literal))
    ConvertFromInt(literal);
  else if (IsFloat(literal))
    ConvertFromFloat(literal);
  else if (IsDouble(literal))
    ConvertFromDouble(literal);
  else {
    std::cout << "Invalid Argument\n";
    return;
  }
  PrintValues(literal);
}

bool ScalarConverter::IsChar(const std::string& literal) {
  if (literal.length() == 1 && std::isdigit(literal[0]) == false) return true;
  return false;
}

bool ScalarConverter::IsInt(const std::string& literal) {
  size_t start = literal[0] == '-' || literal[0] == '+' ? 1 : 0;
  for (size_t i = start; i < literal.length(); i++) {
    if (std::isdigit(literal[i]) == false) return false;
  }
  return true;
}

bool ScalarConverter::IsDouble(const std::string& literal) {
  bool have_point = false;
  size_t start = literal[0] == '-' || literal[0] == '+' ? 1 : 0;
  for (size_t i = start; i < literal.length(); i++) {
    if (std::isdigit(literal[i]) == false) {
      if (literal[i] == '.' && have_point == false)
        have_point = true;
      else
        return false;
    }
  }
  return have_point;
}

bool ScalarConverter::IsFloat(const std::string& literal) {
  bool have_point = false;
  if (literal[literal.length() - 1] != 'f') return false;
  size_t start = literal[0] == '-' || literal[0] == '+' ? 1 : 0;
  for (size_t i = start; i < literal.length() - 1; i++) {
    if (std::isdigit(literal[i]) == false) {
      if (literal[i] == '.' && have_point == false)
        have_point = true;
      else
        return false;
    }
  }
  return have_point;
}

bool ScalarConverter::IsPseudo(const std::string& literal) {
  for (int i = 0; i < 3; i++) {
    if (literal == pseudo_literals_[i]) return true;
  }
  return false;
}

void ScalarConverter::ConvertFromChar(const std::string& literal) {
  int_ = static_cast<int>(literal[0]);
  char_ = static_cast<char>(int_);
  float_ = static_cast<float>(int_);
  double_ = static_cast<double>(int_);
}

void ScalarConverter::ConvertFromInt(const std::string& literal) {
  int_ = std::atoi(literal.c_str());
  char_ = static_cast<char>(int_);
  float_ = static_cast<float>(int_);
  double_ = static_cast<double>(int_);
}

void ScalarConverter::ConvertFromFloat(const std::string& literal) {
  float_ = std::strtof(literal.c_str(), NULL);
  char_ = static_cast<char>(float_);
  int_ = static_cast<int>(float_);
  double_ = static_cast<double>(float_);
}

void ScalarConverter::ConvertFromDouble(const std::string& literal) {
  double_ = std::strtod(literal.c_str(), NULL);
  int_ = static_cast<int>(double_);
  char_ = static_cast<char>(double_);
  float_ = static_cast<float>(double_);
}

void ScalarConverter::PrintValues(const std::string& literal) {
  PrintChar();
  PrintInt();
  PrintFloat(literal);
  PrintDouble(literal);
}

void ScalarConverter::PrintChar() {
  std::cout << "char: ";
  if (int_ < CHAR_MIN || int_ > CHAR_MAX || is_pseudo_)
    std::cout << "Impossible\n";
  else if (isprint(char_) == false)
    std::cout << "Non Displayable\n";
  else
    std::cout << char_ << "\n";
}

void ScalarConverter::PrintInt() {
  std::cout << "int: ";
  if (int_ < INT_MIN || int_ > INT_MAX || is_pseudo_)
    std::cout << "Impossible\n";
  else
    std::cout << int_ << "\n";
}

void ScalarConverter::PrintFloat(const std::string& literal) {
  std::cout << "float: ";
  if (is_pseudo_)
    std::cout << literal << "f\n";
  else
    std::cout << std::fixed << std::setprecision(1) << float_ << "f\n";
};

void ScalarConverter::PrintDouble(const std::string& literal) {
  std::cout << "double: ";
  if (is_pseudo_)
    std::cout << literal << "\n";
  else
    std::cout << std::fixed << std::setprecision(1) << double_ << "\n";
}
