#include <ctime>
#include <iostream>
#include <vector>

#include "PMergeMe.hpp"

double GetTimeInMS(std::clock_t time) {
  double clock_per_ms = static_cast<double>(CLOCKS_PER_SEC) / 1000;
  double time_in_ms = time / clock_per_ms;

  return time_in_ms;
}

double TestVector(int size, char **input, PMergeMe &pmerge) {
  std::clock_t start_time = std::clock();
  std::vector<int> vector_seq = pmerge.MergeSortVector(size, input);
  std::clock_t delta_time = std::clock() - start_time;

  std::cout << "Ordered List using Vector:\n";
  for (std::size_t i = 0; i < vector_seq.size(); i++) {
    std::cout << vector_seq[i] << " ";
  }
  std::cout << "\n";

  return delta_time;
}

double TestDeque(int size, char **input, PMergeMe &pmerge) {
  std::clock_t start_time = std::clock();
  std::deque<int> deque_seq = pmerge.MergeSortDeque(size, input);
  std::clock_t delta_time = std::clock() - start_time;

  std::cout << "Ordered List using Deque:\n";
  for (std::size_t i = 0; i < deque_seq.size(); i++) {
    std::cout << deque_seq[i] << " ";
  }
  std::cout << "\n";

  return delta_time;
}

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
  std::clock_t vector_sort_time = TestVector(argc, argv, pmerge);
  std::clock_t deque_sort_time = TestDeque(argc, argv, pmerge);

  std::cout << "-------------------- SORTING TIME --------------------\n";
  std::cout << "Vector sorting took " << GetTimeInMS(vector_sort_time)
            << " ms\n";
  std::cout << "Deque sorting took " << GetTimeInMS(deque_sort_time) << " ms\n";
}
