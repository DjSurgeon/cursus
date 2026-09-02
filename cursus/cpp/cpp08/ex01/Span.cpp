/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:00:00 by sergio            #+#    #+#             */
/*   Updated: 2026/06/09 13:00:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

// Default constructor
Span::Span() : _N(0) {}

// Parametric constructor
Span::Span(unsigned int N) : _N(N) {}

// Copy constructor
Span::Span(const Span& other) : _N(other._N), _vec(other._vec) {}

// Assignment operator
Span& Span::operator=(const Span& other) {
  if (this != &other) {
    _N = other._N;
    _vec = other._vec;
  }
  return *this;
}

// Destructor
Span::~Span() {}

// Add a single number
void Span::addNumber(int n) {
  if (_vec.size() >= _N) throw ContainerFullException();
  _vec.push_back(n);
}

// Calculate shortest span
int Span::shortestSpan() const {
  if (_vec.size() < 2) throw NotEnoughElementsException();

  // Create a copy to sort, keeping the original container const
  std::vector<int> sortedVec = _vec;
  std::sort(sortedVec.begin(), sortedVec.end());

  std::vector<int> diffs(sortedVec.size());
  std::adjacent_difference(sortedVec.begin(), sortedVec.end(), diffs.begin());

  // The first element of adjacent_difference is just the first element of the
  // source, so we find the minimum starting from the second element.
  return *std::min_element(diffs.begin() + 1, diffs.end());
}

// Calculate longest span
int Span::longestSpan() const {
  if (_vec.size() < 2) throw NotEnoughElementsException();

  int min = *std::min_element(_vec.begin(), _vec.end());
  int max = *std::max_element(_vec.begin(), _vec.end());

  return max - min;
}

// Exceptions
const char* Span::ContainerFullException::what() const throw() {
  return "Error: Span is full. Cannot add more numbers.";
}

const char* Span::NotEnoughElementsException::what() const throw() {
  return "Error: Not enough elements to calculate span (minimum 2 required).";
}
