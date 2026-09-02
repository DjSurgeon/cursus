/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:00:00 by sergio            #+#    #+#             */
/*   Updated: 2026/06/09 13:00:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Default constructor
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

// Copy constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

// Assignment operator
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
  if (this != &other) std::stack<T>::operator=(other);
  return *this;
}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack() {}

// --- Iterators Implementation ---

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
  return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
  return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
  return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
  return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
  return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
  return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
  return this->c.rend();
}
