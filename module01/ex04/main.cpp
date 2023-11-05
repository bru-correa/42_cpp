#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

void OpenInfile(std::ifstream &infile, const char *filename) {
  infile.open(filename);
  if (infile.is_open() == false) {
    std::cout << "The given filename is invalid\n";
    std::exit(1);
  }
}

void OpenOutfile(std::ofstream &outfile, const char *filename) {
  std::string outfilename(filename);
  outfilename.append(".replace");
  outfile.open(outfilename.c_str(), std::ios::out | std::ios::trunc);
  if (outfile.is_open() == false) {
    std::cout << "Could not create output file\n";
    std::exit(1);
  }
}

void ReplaceLine(std::string &line, const char *to_be_replaced,
                 const char *replacement, std::ofstream &outfile) {
  size_t start_pos = 0;
  size_t end_pos = line.find(to_be_replaced);
  size_t replaced_length = std::string(to_be_replaced).length();
  while (end_pos != std::string::npos) {
    outfile << line.substr(start_pos, end_pos - start_pos) << replacement;
    start_pos = end_pos + replaced_length;
    end_pos = line.find(to_be_replaced, start_pos);
  }
  outfile << line.substr(start_pos);
}

void ReplaceFile(std::ifstream &infile, std::ofstream &outfile, const char *s1,
                 const char *s2) {
  std::string line;
  while (std::getline(infile, line)) {
    ReplaceLine(line, s1, s2, outfile);
    if (infile.eof() == false) outfile << "\n";
  }
}

int main(int argc, char *argv[]) {
  if (argc < 4) {
    std::cout << "Invalid arguments!\n";
    return 1;
  }
  std::ifstream infile;
  OpenInfile(infile, argv[1]);
  std::ofstream outfile;
  OpenOutfile(outfile, argv[1]);
  ReplaceFile(infile, outfile, argv[2], argv[3]);
  outfile.close();
  infile.close();
}
