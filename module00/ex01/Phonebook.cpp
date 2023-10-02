#include "Phonebook.hpp"

#include <cstdio>
#include <iomanip>
#include <string>

Phonebook::Phonebook() : oldest_entry_(0) {}

void Phonebook::Add() {
  std::cout << "First Name: ";
  std::string first_name;
  std::getline(std::cin, first_name);
  std::cout << "Last Name: ";
  std::string last_name;
  std::getline(std::cin, last_name);
  std::cout << "Nickname: ";
  std::string nickname;
  std::getline(std::cin, nickname);
  std::cout << "Number: ";
  std::string number;
  std::getline(std::cin, number);
  std::cout << "Secret: ";
  std::string secret;
  std::getline(std::cin, secret);

  Contact new_contact(first_name, last_name, nickname, number, secret);
  contacts_[oldest_entry_] = new_contact;
  oldest_entry_++;
  if (oldest_entry_ >= 8) oldest_entry_ = 0;
  std::cout << "Contact added\n";
}

void Phonebook::Search() {
  if (contacts_[0].IsValid() == false) {
    std::cout << "There is no contact, try adding one with ADD command\n";
    return;
  }
  std::cout << std::right << std::setw(10) << "Index"
            << "|";
  std::cout << std::right << std::setw(10) << "First Name"
            << "|";
  std::cout << std::right << std::setw(10) << "Last Name"
            << "|";
  std::cout << std::right << std::setw(10) << "Nickname\n";
  for (int i = 0; i < 8; i++) {
    if (contacts_[i].IsValid()) {
      DisplayContactShort(i, contacts_[i]);
    }
  }
  int index = -1;
  while (index == -1) {
    std::string input;
    std::cout << "index: ";
    std::getline(std::cin, input);
    index = input[0] - '0';
    if (input.length() > 1 || (index < 0 || index > 8)) {
      std::cout
          << "Invalid input. You must type a valid number between 0 and 8\n";
      index = -1;
      continue;
    }
    if (contacts_[index].IsValid()) {
      DisplayContactFull(contacts_[index]);
      break;
    } else {
      std::cout << "There is no contact with this index\n";
      index = -1;
    }
  }
}

std::string Phonebook::GetShortField(std::string field) {
  std::string short_field;
  short_field = (field.length() > 10) ? field.substr(0, 9) + "." : field;
  return short_field;
}

void Phonebook::DisplayContactShort(int index, Contact contact) {
  std::string first_name = GetShortField(contact.get_first_name());
  std::string last_name = GetShortField(contact.get_last_name());
  std::string nickname = GetShortField(contact.get_nickname());
  std::cout << std::right << std::setw(10) << index << "|";
  std::cout << std::right << std::setw(10) << first_name << "|";
  std::cout << std::right << std::setw(10) << last_name << "|";
  std::cout << std::right << std::setw(10) << nickname << "\n";
}

void Phonebook::DisplayContactFull(Contact contact) {
  std::cout << "First Name: " << contact.get_first_name() << "\n";
  std::cout << "Last Name: " << contact.get_last_name() << "\n";
  std::cout << "Nickname: " << contact.get_nickname() << "\n";
  std::cout << "Number: " << contact.get_number() << "\n";
  std::cout << "Secret: " << contact.get_secret() << "\n";
}
