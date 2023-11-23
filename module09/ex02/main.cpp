#include <iostream>
#include <vector>

#include "PMergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Invalid Input\n";
    return 1;
  }

  std::cout << "Unordered List:\n";
  for (int i = 1; i < argc; i++) {
    std::cout << argv[i] << " ";
  }
  std::cout << "\n";

  PMergeMe pmerge;
  std::vector<int> vector_seq = pmerge.MergeSortVector(argc, argv);

  std::cout << "Ordered List using Vector:\n";
  for (std::size_t i = 0; i < vector_seq.size(); i++) {
    std::cout << vector_seq[i] << " ";
  }
  std::cout << "\n";

  std::deque<int> deque_seq = pmerge.MergeSortDeque(argc, argv);

  std::cout << "Ordered List using Deque:\n";
  for (std::size_t i = 0; i < deque_seq.size(); i++) {
    std::cout << deque_seq[i] << " ";
  }
  std::cout << "\n";
}
