#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class PmergeMe {
 private:
  std::vector<int> _vec;
  std::deque<int> _deq;

  double _timeVec;
  double _timeDeq;

  std::vector<int> _generateJacobsthal(int size) const;
  void _printSequence(const std::string& prefix,
                      const std::vector<int>& seq) const;

  void _sortVector(std::vector<int>& arr);

  void _sortDeque(std::deque<int>& arr);

 public:
  PmergeMe();
  PmergeMe(const PmergeMe& src);
  PmergeMe& operator=(const PmergeMe& rhs);
  ~PmergeMe();

  void sort(int argc, char** argv);

  class ErrorException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif
