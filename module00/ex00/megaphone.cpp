#include <cctype>
#include <cstring>
#include <iostream>

static void print_uppercase(const char *str);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "* LOUD AND UNBERABLE NOISE *\n";
    return (0);
  }
  for (int i = 1; i < argc; i++) {
    print_uppercase(argv[i]);
  }
  std::cout << "\n";
  return 0;
}

static void print_uppercase(const char *str) {
  int length = static_cast<int>(strlen(str));
  for (int i = 0; i < length; i++) {
    if (isalpha(str[i]))
      std::cout << static_cast<char>(toupper(str[i]));
    else
      std::cout << str[i];
  }
}
