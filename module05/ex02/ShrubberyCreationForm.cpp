#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Colors.hpp"

/* CONSTRUCTORS */
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target_(""){};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target_(target){};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src)
    : AForm(src), target_(src.target_){};

/* DESTRUCTORS */
ShrubberyCreationForm::~ShrubberyCreationForm(){};

/* OVERLOADS */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm &rhs) {
  if (this != &rhs) {
    throw UnassignableException();
  }
  return *this;
}

/* METHODS */
void ShrubberyCreationForm::Action() const {
  std::ofstream outFile;
  try {
    outFile.open((target_ + "_shrubbery").c_str());

  } catch (const std::exception &e) {
    std::cerr << RED << e.what() << RESET << "\n";
    return;
  }
  std::string forest =
      "       ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^\n";
  forest.append(
      "      /|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ "
      "/|\\/|\\\n");
  forest.append(
      "      /|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ "
      "/|\\/|\\\n");
  forest.append(
      "      /|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ "
      "/|\\/|\\\n");
  outFile << forest;
}
