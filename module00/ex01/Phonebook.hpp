#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#endif  // PHONEBOOK_H

#include "Contact.hpp"

class Phonebook {
 private:
  int oldest_entry_;
  Contact contacts_[8];

  std::string GetShortField(std::string field);
  void DisplayContactShort(int index, Contact contact);
  void DisplayContactFull(Contact contact);

 public:
  Phonebook();
  void Add();
  void Search();
  void Exit();
};
