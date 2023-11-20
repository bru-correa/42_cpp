#ifndef ARRAY_H
#define ARRAY_H

#include <exception>

template <typename T>
class Array {
 public:
  Array() : size_(0), content_(new T[0]) {}

  Array(unsigned int size) : size_(size), content_(new T[size]) {}

  Array(Array &src) : size_(src.size_), content_(new T[src.size_]) {
    for (unsigned int i = 0; i < size_; i++) {
      content_[i] = src.content_[i];
    }
  }

  ~Array() { delete[] content_; }

  Array &operator=(Array &rhs) {
    if (this == &rhs) return *this;
    if (size_ != rhs.size_) {
      delete[] content_;
      size_ = rhs.size_;
      content_ = new T[size_];
    }
    for (unsigned int i = 0; i < size_; i++) content_[i] = rhs.content_[i];
    return *this;
  }

  T &operator[](const unsigned int pos) {
    if (pos >= size_) throw IndexOutOfBoundsException();
    return content_[pos];
  }

  T const &operator[](const unsigned int pos) const {
    if (pos >= size_) throw IndexOutOfBoundsException();
    return content_[pos];
  }

  unsigned int get_size() const { return size_; }

 private:
  unsigned int size_;
  T *content_;

 private:
  class IndexOutOfBoundsException : public std::exception {
    const char *what() const throw() { return "Index Out of Bounds"; }
  };
};

#endif  // !ARRAY_H
