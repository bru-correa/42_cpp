#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <stdint.h>

#include <string>

class Data;

class Serializer {
 public:
  static uintptr_t Serialize(Data *ptr);
  static Data *Deserialize(uintptr_t raw);

 private:
  Serializer();
  Serializer(Serializer &src);
  ~Serializer();

  Serializer &operator=(Serializer &rhs);
};

#endif  // !SERIALIZER_H
