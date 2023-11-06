#ifndef HARL_H
#define HARL_H

#include <string>

class Harl {
 public:
  void Complain(std::string level);

 private:
  void Debug();
  void Info();
  void Warning();
  void Error();
};

#endif  // !HARL_H
