#include <vector>

class Span {
 public:
  Span();
  Span(unsigned int size);
  Span(Span &src);
  ~Span();
  Span &operator=(const Span &rhs);

  void AddNumber(int n);
  int ShortestSpan();
  int LongestSpan();
  void FillWithRandom();

 private:
  std::vector<int> data_;
  unsigned int max_elements_;

 private:
  class SpanFullException : public std::exception {
   public:
    const char *what() const throw();
  };
  class SpanEmptyException : public std::exception {
   public:
    const char *what() const throw();
  };
};
