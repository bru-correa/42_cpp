#include "PMergeMe.hpp"

#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

/* CONSTRUCTOR */
PMergeMe::PMergeMe(){};

PMergeMe::PMergeMe(PMergeMe &src) { *this = src; }

/* DESTRUCTOR */
PMergeMe::~PMergeMe(){};

/* OVERLOADS */
PMergeMe &PMergeMe::operator=(const PMergeMe &rhs) {
  if (this != &rhs) return *this;
  return *this;
}

/* METHODS */

/********** VECTOR **********/

std::vector<int> PMergeMe::MergeSortVector(int length, char **input) {
  std::vector<int> sequence;
  for (int i = 1; i < length; i++) {
    sequence.push_back(std::atoi(input[i]));
  }
  Sort(sequence, 0, sequence.size() - 1);
  return sequence;
}

void PMergeMe::Merge(std::vector<int> &sequence, int begin, int middle,
                     int end) {
  std::vector<int> left_vector(sequence.begin() + begin,
                               sequence.begin() + middle + 1);
  std::vector<int> right_vector(sequence.begin() + middle + 1,
                                sequence.begin() + end + 1);
  size_t right_index = 0;
  size_t left_index = 0;
  size_t length = left_vector.size() + right_vector.size();
  for (size_t i = begin; i < begin + length; i++) {
    if (right_index == right_vector.size()) {
      sequence[i] = left_vector[left_index];
      left_index++;
    } else if (left_index == left_vector.size()) {
      sequence[i] = right_vector[right_index];
      right_index++;
    } else if (right_vector[right_index] > left_vector[left_index]) {
      sequence[i] = left_vector[left_index];
      left_index++;
    } else {
      sequence[i] = right_vector[right_index];
      right_index++;
    }
  }
}
void PMergeMe::InsertionSort(std::vector<int> &sequence, int begin, int end) {
  for (int i = begin; i < end; i++) {
    int temp = sequence[i + 1];
    int j = i + 1;
    while (j > begin && sequence[j - 1] > temp) {
      sequence[j] = sequence[j - 1];
      j--;
    }
    sequence[j] = temp;
  }
}

void PMergeMe::Sort(std::vector<int> &sequence, int begin, int end) {
  if (end - begin > 5) {
    int middle = (begin + end) / 2;
    Sort(sequence, begin, middle);
    Sort(sequence, middle + 1, end);
    Merge(sequence, begin, middle, end);
  } else {
    InsertionSort(sequence, begin, end);
  }
}

/********** LIST **********/

std::deque<int> PMergeMe::MergeSortDeque(int length, char **input) {
  std::deque<int> sequence;
  for (int i = 1; i < length; i++) {
    sequence.push_back(std::atoi(input[i]));
  }
  Sort(sequence, 0, sequence.size() - 1);
  return sequence;
}

void PMergeMe::Merge(std::deque<int> &sequence, int begin, int middle,
                     int end) {
  std::deque<int> left_deque(sequence.begin() + begin,
                             sequence.begin() + middle + 1);
  std::deque<int> right_deque(sequence.begin() + middle + 1,
                              sequence.begin() + end + 1);
  size_t right_index = 0;
  size_t left_index = 0;
  size_t length = left_deque.size() + right_deque.size();
  for (size_t i = begin; i < begin + length; i++) {
    if (right_index == right_deque.size()) {
      sequence[i] = left_deque[left_index];
      left_index++;
    } else if (left_index == left_deque.size()) {
      sequence[i] = right_deque[right_index];
      right_index++;
    } else if (right_deque[right_index] > left_deque[left_index]) {
      sequence[i] = left_deque[left_index];
      left_index++;
    } else {
      sequence[i] = right_deque[right_index];
      right_index++;
    }
  }
}
void PMergeMe::InsertionSort(std::deque<int> &sequence, int begin, int end) {
  for (int i = begin; i < end; i++) {
    int temp = sequence[i + 1];
    int j = i + 1;
    while (j > begin && sequence[j - 1] > temp) {
      sequence[j] = sequence[j - 1];
      j--;
    }
    sequence[j] = temp;
  }
}

void PMergeMe::Sort(std::deque<int> &sequence, int begin, int end) {
  if (end - begin > 5) {
    int middle = (begin + end) / 2;
    Sort(sequence, begin, middle);
    Sort(sequence, middle + 1, end);
    Merge(sequence, begin, middle, end);
  } else {
    InsertionSort(sequence, begin, end);
  }
}
/* EXCEPTIONS */
