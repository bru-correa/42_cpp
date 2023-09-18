#ifndef CONTACT_H
#define CONTACT_H
#endif  // CONTACT_H

#include <iostream>
#include <string>

class Contact {
 public:
  Contact();
  Contact(std::string first_name, std::string last_name, std::string nickname,
          std::string number, std::string secret);
  std::string get_first_name();
  std::string get_last_name();
  std::string get_nickname();
  std::string get_number();
  std::string get_secret();

  void set_first_name(std::string first_name);
  void set_last_name(std::string last_name);
  void set_nickname(std::string nickname);
  void set_number(std::string number);
  void set_secret(std::string secret);

  void Print();

 private:
  std::string first_name_;
  std::string last_name_;
  std::string nickname_;
  std::string number_;
  std::string secret_;
};
