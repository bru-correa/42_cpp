#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
  Data origin_data(42, "forty-two");

  uintptr_t serialized_address = Serializer::Serialize(&origin_data);
  Data *des_data = Serializer::Deserialize(serialized_address);

  std::cout << "Origin:\n";
  std::cout << "number: " << origin_data.number << "\n";
  std::cout << "string: " << origin_data.str << "\n";
  std::cout << "address:: " << &origin_data << "\n";

  std::cout << "Deserialized:\n";
  std::cout << "number: " << des_data->number << "\n";
  std::cout << "string: " << des_data->str << "\n";
  std::cout << "address:: " << &des_data << "\n";
}
