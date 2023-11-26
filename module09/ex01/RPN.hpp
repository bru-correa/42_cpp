#ifndef RPN_H
#define RPN_H

#include <exception>
#include <stack>
#include <string>

class RPN {
 public:
  RPN();
  RPN(RPN &src);
  ~RPN();

  RPN &operator=(const RPN &rhs);

  void ExecuteOperation(const std::string input);

 private:
  static std::string operators;
  static const int max_chars;

  std::stack<int> stack_;

  void PushResult(const char c);
  int GetResult(const int a, const int b, const char op) const;
  bool IsOperand(const char c) const;
  bool isOperator(const char c) const;

 private:
  class InvalidInput : public std::exception {
    virtual const char *what() const throw();
  };
  class InvalidOperator : public std::exception {
    virtual const char *what() const throw();
  };
  class InvalidOperands : public std::exception {
    virtual const char *what() const throw();
  };
};

#endif  // !RPN_H
