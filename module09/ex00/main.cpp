#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

std::set<std::string> GetDates() {
  std::ifstream infile("./data.csv");

  std::set<std::string> dates;
  std::string line;
  while (std::getline(infile, line)) {
    dates.insert(line);
  }
  return dates;
}

int main() {
  std::set<std::string> dates = GetDates();
  std::string specific_date("2015-10-10");

  std::string bitcoin_str("0.8");
  double bitcoin = std::strtod(bitcoin_str.c_str(), NULL);

  std::set<std::string>::iterator it = dates.lower_bound(specific_date);
  if ((*it).substr(0, 10) != specific_date) it--;
  std::string date((*it).substr(0, 10));
  std::string rate_str((*it).substr(11, (*it).length() - 11));
  double rate = std::strtod(rate_str.c_str(), NULL);

  std::cout << (*it) << "\n";
  std::cout << specific_date << " => " << bitcoin << " = " << rate * bitcoin
            << "\n";
}
