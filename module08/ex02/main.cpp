#include <iostream>
#include <list>

#include "MutantStack.hpp"

void PrintStack(MutantStack<int> &mstack) {
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
       it++) {
    std::cout << *it << ' ';
  }
  std::cout << "\n\n";
}

void TestPdf() {
  std::cout << "---------------- PDF TEST ----------------\n";

  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << "Top: " << mstack.top() << "\n";
  mstack.pop();
  std::cout << "Size: " << mstack.size() << "\n";
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << "\n";
    ++it;
  }
  std::stack<int> s(mstack);
}

void TestIterator() {
  std::cout << "---------------- ITERATOR TEST ---------------\n";

  MutantStack<int> mstack0;
  mstack0.push(6);
  mstack0.push(12);
  mstack0.push(18);
  mstack0.push(24);
  mstack0.push(32);

  MutantStack<int> mstack1(mstack0);
  MutantStack<int> mstack2 = mstack1;

  std::cout << "mstack0 Top: " << mstack0.top() << "\n";
  std::cout << "mstack0 Size: " << mstack0.size() << "\n";
  PrintStack(mstack0);

  std::cout << "mstack1 Top: " << mstack1.top() << "\n";
  std::cout << "mstack1 Size: " << mstack1.size() << "\n";
  PrintStack(mstack1);

  std::cout << "mstack2 Top: " << mstack2.top() << "\n";
  std::cout << "mstack2 Size: " << mstack2.size() << "\n";
  PrintStack(mstack2);
}

int main() {
  TestPdf();
  TestIterator();
}
