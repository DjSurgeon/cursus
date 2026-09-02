/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:00:00 by sergio            #+#    #+#             */
/*   Updated: 2026/06/09 13:00:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iterator>
#include <vector>

class Span {
 private:
  unsigned int _N;
  std::vector<int> _vec;

 public:
  // Canonical Orthodox Form
  Span();
  Span(unsigned int N);
  Span(const Span& other);
  Span& operator=(const Span& other);
  ~Span();

  // Methods
  void addNumber(int n);
  int shortestSpan() const;
  int longestSpan() const;

  // Add Number by Range (Template)
  template <typename Iterator>
  void addNumber(Iterator begin, Iterator end) {
    if (std::distance(begin, end) > static_cast<long>(_N - _vec.size()))
      throw ContainerFullException();
    _vec.insert(_vec.end(), begin, end);
  }

  // Exceptions
  class ContainerFullException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class NotEnoughElementsException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif
