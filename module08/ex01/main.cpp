#include <iostream>

#include "Span.hpp"

void TestInvalidSpan() {
  std::cout << "--------------- INVALID SPAN TESTS ---------------\n";
  try {
    Span invalid;
    invalid.AddNumber(6);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    Span invalid(1);
    invalid.AddNumber(2);
    invalid.ShortestSpan();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    Span invalid(1);
    invalid.AddNumber(2);
    invalid.LongestSpan();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    Span invalid(2);
    invalid.AddNumber(2);
    invalid.AddNumber(3);
    invalid.AddNumber(4);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

void TestNegativeSpan() {
  std::cout << "---------------- NEGATIVE SPAN TESTS ----------------\n";

  Span negative_span(5);

  negative_span.AddNumber(-6);
  negative_span.AddNumber(3);
  negative_span.AddNumber(-17);
  negative_span.AddNumber(9);
  negative_span.AddNumber(-11);
  std::cout << "Shortest span: " << negative_span.ShortestSpan() << "\n";
  std::cout << "Longest span: " << negative_span.LongestSpan() << "\n";
}

void TestSmallSpan() {
  std::cout << "---------------- SMALL SPAN TESTS ----------------\n";

  Span small_span(5);

  small_span.AddNumber(6);
  small_span.AddNumber(3);
  small_span.AddNumber(17);
  small_span.AddNumber(9);
  small_span.AddNumber(11);
  std::cout << "Shortest span: " << small_span.ShortestSpan() << "\n";
  std::cout << "Longest span: " << small_span.LongestSpan() << "\n";
}

void TestBigSpan() {
  std::cout << "------------------ BIG SPAN TESTS ------------------\n";

  Span big_span(20000);

  big_span.FillWithRandom();
  std::cout << "&sp1: " << &big_span << "\n";
  std::cout << "Shortest span: " << big_span.ShortestSpan() << "\n";
  std::cout << "Longest span: " << big_span.LongestSpan() << "\n";
  std::cout << "\n";
}

int main() {
  TestInvalidSpan();
  TestNegativeSpan();
  TestSmallSpan();
  TestBigSpan();
  return (0);
}
