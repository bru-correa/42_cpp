#include "Span.hpp"

#include <algorithm>
#include <cstdlib>
#include <ctime>

Span::Span() : max_elements_(0) {}

Span::Span(unsigned int n) : max_elements_(n) {}

Span::Span(Span &src) { *this = src; }

Span::~Span(){};

Span &Span::operator=(const Span &rhs) {
  if (this == &rhs) return *this;
  max_elements_ = rhs.max_elements_;
  data_ = rhs.data_;
  return *this;
}

void Span::AddNumber(int n) {
  if (data_.size() < max_elements_)
    data_.push_back(n);
  else
    throw SpanFullException();
}

int Span::ShortestSpan() {
  if (data_.size() < 2) throw Span::SpanEmptyException();
  std::sort(data_.begin(), data_.end());
  int shortest_span = std::abs(data_.at(1) - data_.at(0));
  for (size_t i = 1; i < data_.size() - 1; i++) {
    if (std::abs(data_.at(i + 1) - data_.at(i)) < shortest_span) {
      shortest_span = std::abs(data_.at(i + 1) - data_.at(i));
    }
  }
  return shortest_span;
}

int Span::LongestSpan() {
  if (data_.size() < 2) throw SpanEmptyException();
  return (*std::max_element(data_.begin(), data_.end()) -
          *std::min_element(data_.begin(), data_.end()));
}

void Span::FillWithRandom() {
  std::srand(time(0));
  if (data_.size() >= max_elements_) throw SpanFullException();
  for (size_t i = 0; i < max_elements_; i++) {
    data_.push_back(rand());
  }
}

const char *Span::SpanFullException::what() const throw() {
  return "The Span is full";
}

const char *Span::SpanEmptyException::what() const throw() {
  return "The Span is full";
}
