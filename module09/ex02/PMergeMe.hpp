#ifndef PMERGE_ME_H
#define PMERGE_ME_H

#include <deque>
#include <list>
#include <vector>
class PMergeMe {
 public:
  PMergeMe();
  PMergeMe(PMergeMe &src);
  ~PMergeMe();

  PMergeMe &operator=(const PMergeMe &rhs);

  std::vector<int> MergeSortVector(int length, char **input);
  std::deque<int> MergeSortDeque(int length, char **input);

 private:
  void Merge(std::vector<int> &sequence, int begin, int middle, int end);
  void InsertionSort(std::vector<int> &sequence, int begin, int end);
  void Sort(std::vector<int> &sequence, int begin, int end);

  void Merge(std::deque<int> &sequence, int begin, int middle, int end);
  void InsertionSort(std::deque<int> &sequence, int begin, int end);
  void Sort(std::deque<int> &sequence, int begin, int end);
};

#endif  // !PMERGE_ME_H
