#include "RPN.hpp"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>

std::string operators("+-*/");
int max_chars = 16;

/* CONSTRUCTOR */
RPN::RPN(){};

RPN::RPN(RPN &src) { *this = src; };

/* DESTRUCTOR */
RPN::~RPN(){};

/* OVERLOADS */
RPN &RPN::operator=(const RPN &rhs) {
  if (this != &rhs) return *this;
  stack_ = rhs.stack_;
  return *this;
}

/* METHODS */
bool RPN::IsOperand(const char c) const {
  return std::isdigit(c) ? true : false;
}

bool RPN::isOperator(const char c) const {
  switch (c) {
    case '+':
      return true;
    case '-':
      return true;
    case '*':
      return true;
    case '/':
      return true;
    default:
      return false;
  }
}

void RPN::ExecuteOperation(const std::string input) {
  if (input.empty())
    throw InvalidInput();
  else if (isOperator(input[input.length() - 1]) == false)
    throw InvalidInput();
  int operations_count = 0;
  for (size_t i = 0; i < input.length(); i++) {
    if (input[i] == ' ')
      continue;
    else if (IsOperand(input[i])) {
      if (stack_.size() == 2)
        throw InvalidInput();
      else if (i > 0 && std::isdigit(input[i - 1]))
        throw InvalidInput();
      stack_.push(input[i] - '0');
    } else if (isOperator(input[i])) {
      PushResult(input[i]);
      operations_count++;
    }
    if (operations_count > 6) throw TooManyOperations();
  }
  std::cout << "Result: " << stack_.top() << "\n";
  stack_.pop();
}

void RPN::PushResult(const char c) {
  if (stack_.size() != 2) throw InvalidInput();
  int a = stack_.top();
  stack_.pop();
  int b = stack_.top();
  stack_.pop();
  stack_.push(GetResult(b, a, c));
}

int RPN::GetResult(const int a, const int b, const char op) const {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    default:
      throw InvalidInput();
  }
}

/* EXCEPTIONS */
const char *RPN::InvalidInput::what() const throw() { return "Invalid Input"; }

const char *RPN::TooManyOperations::what() const throw() {
  return "There are too many operations passed as input";
}
