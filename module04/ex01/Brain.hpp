#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain {
 public:
  std::string ideas[100];
  Brain();
  Brain(Brain &src);
  ~Brain();

  Brain &operator=(Brain &rhs);
};

#endif  // !BRAIN_H
