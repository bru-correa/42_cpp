#include "Serializer.hpp"

#include "Data.hpp"

/* CONSTRUCTORS */
Serializer::Serializer(){};

Serializer::Serializer(Serializer &src) { *this = src; }

/* DESTRUCTOR */
Serializer::~Serializer(){};

/* OVERLOADS */
Serializer &Serializer::operator=(Serializer &rhs) {
  return this == &rhs ? *this : *this;
}

/* METHODS */
uintptr_t Serializer::Serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::Deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
