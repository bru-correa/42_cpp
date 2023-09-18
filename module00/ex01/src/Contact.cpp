#include "./Contact.hpp"

Contact::Contact() {
  first_name_ = "";
  last_name_ = "";
  nickname_ = "";
  number_ = "";
  secret_ = "";
}

Contact::Contact(std::string first_name, std::string last_name,
                 std::string nickname, std::string number, std::string secret) {
  first_name_ = first_name;
  last_name_ = last_name;
  nickname_ = nickname;
  number_ = number;
  secret_ = secret;
}

std::string Contact::get_first_name() { return first_name_; }
std::string Contact::get_last_name() { return last_name_; }
std::string Contact::get_nickname() { return nickname_; }
std::string Contact::get_number() { return number_; }
std::string Contact::get_secret() { return secret_; }

void Contact::set_first_name(std::string first_name) {
  first_name_ = first_name;
}
void Contact::set_last_name(std::string last_name) { last_name_ = last_name; }
void Contact::set_nickname(std::string nickname) { nickname_ = nickname; }
void Contact::set_number(std::string number) { number_ = number; }
void Contact::set_secret(std::string secret) { secret_ = secret; }

void Contact::Print() {
  std::cout << first_name_ << '\n';
  std::cout << last_name_ << '\n';
  std::cout << nickname_ << '\n';
  std::cout << number_ << '\n';
  std::cout << secret_ << '\n';
}
