#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#endif  // PHONEBOOK_H

#include "./Contact.hpp"

class Phonebook {
 private:
  int oldest_entry_;
  Contact contacts[8];

 public:
  Phonebook();
  void Add();
  void Search();
  void Exit();
};
