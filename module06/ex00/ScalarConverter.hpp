#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
 public:
  static void Convert(const std::string& src);

 private:
  static const std::string pseudo_literals_[3];

  static char char_;
  static long int_;
  static float float_;
  static double double_;
  static bool is_pseudo_;

  ScalarConverter();
  ScalarConverter(ScalarConverter const& literal);
  ~ScalarConverter();

  ScalarConverter& operator=(ScalarConverter const& rhs);

  static void ConvertFromChar(const std::string& literal);
  static void ConvertFromFloat(const std::string& literal);
  static void ConvertFromInt(const std::string& literal);
  static void ConvertFromDouble(const std::string& literal);

  static bool IsChar(const std::string& literal);
  static bool IsFloat(const std::string& literal);
  static bool IsInt(const std::string& literal);
  static bool IsDouble(const std::string& literal);
  static bool IsPseudo(const std::string& literal);

  static void PrintValues(const std::string& literal);

  static void PrintChar();
  static void PrintInt();
  static void PrintFloat(const std::string& literal);
  static void PrintDouble(const std::string& literal);
};

#endif
