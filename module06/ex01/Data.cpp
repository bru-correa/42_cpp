#include "Data.hpp"

/* CONSTRUCTORS */
Data::Data() : number(6), str("Data"){};

Data::Data(int number, std::string str) : number(number), str(str){};

Data::Data(Data &src) { *this = src; }

/* DESTRUCTOR */
Data::~Data(){};

/* OVERLOADS */
Data &Data::operator=(Data &rhs) {
  if (this == &rhs) return *this;
  number = rhs.number;
  str = rhs.str;
  return *this;
}
