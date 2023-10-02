#include "Phonebook.hpp"

#include <cstdio>
#include <iomanip>
#include <string>

#include "SetColor.hpp"

Phonebook::Phonebook() : oldest_entry_(0) {}

void Phonebook::Add() {
  std::cout << SetBlueColor("First Name: ");
  std::string first_name;
  std::getline(std::cin, first_name);
  std::cout << SetBlueColor("Last Name: ");
  std::string last_name;
  std::getline(std::cin, last_name);
  std::cout << SetBlueColor("Nickname: ");
  std::string nickname;
  std::getline(std::cin, nickname);
  std::cout << SetBlueColor("Number: ");
  std::string number;
  std::getline(std::cin, number);
  std::cout << SetBlueColor("Secret: ");
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
    std::cout << SetRedColor(
        "There is no contact, try adding one with ADD command\n");
    return;
  }
  DisplayContactList();
  SearchIndex();
}

// Private

void Phonebook::DisplayContactList() {
  SetBufferBlue();
  std::cout << std::right << std::setw(10) << "Index"
            << "|";
  std::cout << std::right << std::setw(10) << "First Name"
            << "|";
  std::cout << std::right << std::setw(10) << "Last Name"
            << "|";
  std::cout << std::right << std::setw(10) << "Nickname\n";
  ResetBufferColor();
  for (int i = 0; i < 8; i++) {
    if (contacts_[i].IsValid()) {
      DisplayContactShort(i, contacts_[i]);
    }
  }
}

void Phonebook::SearchIndex() {
  int index = -1;
  while (index == -1) {
    std::string input;
    std::cout << "index: ";
    std::getline(std::cin, input);
    index = input[0] - '0';
    if (input.length() > 1 || (index < 0 || index > 8)) {
      std::cout << SetRedColor(
          "Invalid input. You must type a valid number between 0 and 8\n");
      index = -1;
      continue;
    }
    if (contacts_[index].IsValid()) {
      DisplayContactFull(contacts_[index]);
      break;
    } else {
      std::cout << SetRedColor("There is no contact with this index\n");
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
  std::cout << SetBlueColor("First Name: ") << contact.get_first_name() << "\n";
  std::cout << SetBlueColor("Last Name: ") << contact.get_last_name() << "\n";
  std::cout << SetBlueColor("Nickname: ") << contact.get_nickname() << "\n";
  std::cout << SetBlueColor("Number: ") << contact.get_number() << "\n";
  std::cout << SetBlueColor("Secret: ") << contact.get_secret() << "\n";
}
