#include "weapon.hpp"

Weapon::Weapon(std::string type) : type_(type){};

const std::string& Weapon::get_type() {
  const std::string& type = type_;
  return type;
}

void Weapon::set_type(std::string type) { type_ = type; }
