#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
 public:
  const char *what() const throw() { return "Not Found\n"; }
};

template <typename T>
typename T::iterator EasyFind(T &container, int n) {
  typename T::iterator it = std::find(container.begin(), container.end(), n);
  if (it == container.end()) throw NotFoundException();
  return it;
}
