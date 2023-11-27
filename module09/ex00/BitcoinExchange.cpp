#include "BitcoinExchange.hpp"

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

/* CONSTRUCTORS */
BitcoinExchange::BitcoinExchange() { throw InvalidDatabaseFile(); }

BitcoinExchange::BitcoinExchange(std::string data_filename) {
  std::ifstream db_file(data_filename.c_str());
  if (db_file.is_open() == false) throw InvalidDatabaseFile();
  // Skip first line
  std::string line;
  std::getline(db_file, line);
  while (std::getline(db_file, line)) {
    database_.insert(line);
  }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src) { *this = src; }

/* DESTRUCTOR */
BitcoinExchange::~BitcoinExchange() {}

/* OVERLOADS */
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &rhs) {
  if (this == &rhs) return *this;
  database_ = rhs.database_;
  return *this;
}

/* METHODS */
void BitcoinExchange::ParseFile(std::string filename) {
  std::ifstream input_file(filename.c_str());
  if (input_file.is_open() == false) throw InvalidInputFile();

  std::string line;
  // Skip the header in the first line
  std::getline(input_file, line);
  while (std::getline(input_file, line)) {
    PrintExchangeRate(line);
  }
}

void BitcoinExchange::PrintExchangeRate(const std::string &line) const {
  try {
    std::string date = GetLineDate(line);
    float bitcoin = GetBitcoin(line);
    float exchange_rate = GetExchangeRate(date);
    std::cout << date << " => " << bitcoin << " = " << bitcoin * exchange_rate
              << "\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    return;
  }
}

std::string BitcoinExchange::GetLineDate(const std::string &line) const {
  if (line.empty()) throw InvalidInput();
  CheckDateFormat(line);
  CheckDate(line);
  if (line.substr(10, 3) != " | ") throw InvalidInput();
  return line.substr(0, 10);
}

void BitcoinExchange::CheckDateFormat(const std::string &line) const {
  CheckForDigits(line, 0, 4);
  if (line[4] != '-') throw InvalidDate();
  CheckForDigits(line, 5, 2);
  if (line[7] != '-') throw InvalidDate();
  CheckForDigits(line, 8, 2);
}

void BitcoinExchange::CheckForDigits(const std::string &line, const int &start,
                                     const int &length) const {
  for (int i = start; i < length; i++) {
    if (!line[i])
      throw InvalidDate();
    else if (std::isdigit(line[i]) == false)
      throw InvalidDate();
  }
}

void BitcoinExchange::CheckDate(const std::string &line) const {
  std::string month(line.substr(5, 2));
  if (std::atoi(month.c_str()) > 12) throw InvalidDate();
  std::string day(line.substr(8, 2));
  if (std::atoi(day.c_str()) > 31) throw InvalidDate();
}

float BitcoinExchange::GetBitcoin(const std::string &line) const {
  std::string bitcoin_str(line.substr(13, line.length() - 13));
  float bitcoin = std::strtof(bitcoin_str.c_str(), NULL);
  if (bitcoin == 0)
    throw InvalidInput();
  else if (bitcoin < 0)
    throw BitcoinNegative();
  else if (bitcoin > 1000)
    throw BitcoinTooLarge();
  return bitcoin;
}

float BitcoinExchange::GetExchangeRate(const std::string &date) const {
  std::set<std::string>::iterator it = database_.lower_bound(date);
  if (it == database_.end())
    it--;
  else if (it != database_.begin() && (*it).substr(0, 10) != date) {
    --it;
  }
  std::string line((*it));
  int length = line.length() - 11;
  std::string rate_str(line.substr(11, length));
  float exchange_rate = std::strtof(rate_str.c_str(), NULL);
  return exchange_rate;
}

/* EXCEPTIONS */
const char *BitcoinExchange::InvalidDatabaseFile::what() const throw() {
  return "Error: Can't open the database file";
}

const char *BitcoinExchange::InvalidInputFile::what() const throw() {
  return "Error: Can't open the input file to be parsed";
}

const char *BitcoinExchange::InvalidDate::what() const throw() {
  return "Error: Invalid date provided in input file";
}

const char *BitcoinExchange::InvalidInput::what() const throw() {
  return "Error: Invalid input";
}

const char *BitcoinExchange::BitcoinNegative::what() const throw() {
  return "Error: The number is not positive";
};
const char *BitcoinExchange::BitcoinTooLarge::what() const throw() {
  return "Error: The number is too large";
};
