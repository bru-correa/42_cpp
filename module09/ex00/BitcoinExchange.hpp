#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H

#include <exception>
#include <fstream>
#include <set>
#include <string>

class BitcoinExchange {
 public:
  BitcoinExchange(std::string data_filename);
  BitcoinExchange(BitcoinExchange &src);
  ~BitcoinExchange();

  BitcoinExchange &operator=(BitcoinExchange &rhs);

  void ParseFile(std::string filename);
  void PrintExchangeRate(const std::string &line) const;

 private:
  BitcoinExchange();

  std::ifstream input_file_;
  std::set<std::string> database_;

  float GetExchangeRate(const std::string &date) const;

  /* PARSE */
  void CheckDateFormat(const std::string &line) const;
  void CheckForDigits(const std::string &line, const int &start,
                      const int &length) const;
  void CheckDate(const std::string &line) const;
  std::string GetLineDate(const std::string &line) const;
  float GetBitcoin(const std::string &line) const;

 private:
  class InvalidDatabaseFile : public std::exception {
    virtual const char *what() const throw();
  };
  class InvalidInputFile : public std::exception {
    virtual const char *what() const throw();
  };
  class InvalidDate : public std::exception {
    virtual const char *what() const throw();
  };
  class InvalidInput : public std::exception {
    virtual const char *what() const throw();
  };
  class BitcoinNegative : public std::exception {
    virtual const char *what() const throw();
  };
  class BitcoinTooLarge : public std::exception {
    virtual const char *what() const throw();
  };
};

#endif  // !BITCOIN_EXCHANGE_H
