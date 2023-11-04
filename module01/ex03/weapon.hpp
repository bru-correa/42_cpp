#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "string"

class Weapon {
 public:
  Weapon(std::string type);
  const std::string& get_type();
  void set_type(std::string type);

 private:
  std::string type_;
};

#endif  // !WEAPON_HPP
