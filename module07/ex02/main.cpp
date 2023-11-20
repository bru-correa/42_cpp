#include <iostream>

#include "Array.hpp"

template <typename T>
void PrintArray(T array) {
  std::cout << "[";
  for (unsigned int i = 0; i < array.get_size(); i++) {
    std::cout << array[i] << " ";
  }
  std::cout << "]\n";
}

void TestSimpleType() {
  std::cout << "------------------ SIMPLE TYPE TEST ------------------\n";

  Array<int> int_array(5);

  std::cout << "Test read and write:\n";
  for (unsigned int i = 0; i < int_array.get_size(); i++) {
    int_array[i] = i;
  }
  PrintArray(int_array);

  std::cout << "Test copy:\n";
  Array<int> copy_array;
  copy_array = int_array;
  PrintArray(copy_array);

  std::cout << "Original:\n";
  PrintArray(int_array);
}

void TestComplexType() {
  std::cout << "------------------ COMPLEX TYPE TEST ------------------\n";

  Array<std::string> str_array(3);

  std::cout << "Test read and write:\n";
  str_array[0] = "Hi";
  str_array[1] = "Hello";
  str_array[2] = "Greetings";
  PrintArray(str_array);

  std::cout << "Test copy:\n";
  Array<std::string> copy_array;
  copy_array = str_array;
  PrintArray(copy_array);

  std::cout << "Original:\n";
  PrintArray(str_array);
}

int main() {
  TestSimpleType();
  TestComplexType();
}
