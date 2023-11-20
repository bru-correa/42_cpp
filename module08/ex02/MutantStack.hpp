#ifndef MUTANT_STACK_H
#define MUTANT_STACK_H

#include <deque>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
 public:
  MutantStack() {}
  MutantStack(const MutantStack &src) : std::stack<T, Container>(src){};
  ~MutantStack() {}

  MutantStack &operator=(MutantStack const &rhs) {
    std::stack<T, Container>::operator=(rhs);
    return *this;
  }
  typedef typename Container::iterator iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
};

#endif  // !MUTANT_STACK_H
