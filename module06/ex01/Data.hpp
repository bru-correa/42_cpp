#ifndef DATA_H
#define DATA_H

#include <string>

class Data {
 public:
  Data();
  Data(int number, std::string str);
  Data(Data &src);
  ~Data();

  Data &operator=(Data &rhs);

  int number;
  std::string str;
};

#endif  // !DATA_H
