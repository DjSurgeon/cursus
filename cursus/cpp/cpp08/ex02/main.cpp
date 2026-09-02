/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:00:00 by sergio            #+#    #+#             */
/*   Updated: 2026/06/09 13:00:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>
#include <string>

#include "MutantStack.hpp"

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

int main() {
  std::cout << YELLOW
            << "\n========== 1. SUBJECT TEST (MutantStack) ==========" << RESET
            << std::endl;

  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);

  std::cout << "Top element: " << GREEN << mstack.top() << RESET << std::endl;

  mstack.pop();

  std::cout << "Size after pop: " << GREEN << mstack.size() << RESET
            << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;

  std::cout << CYAN << "Stack content (bottom to top):" << RESET << std::endl;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);  // Test copy constructor for std::stack

  std::cout << YELLOW
            << "\n========== 2. EQUIVALENT TEST (std::list) ==========" << RESET
            << std::endl;

  std::list<int> list_stack;
  list_stack.push_back(5);
  list_stack.push_back(17);

  std::cout << "Top element: " << GREEN << list_stack.back() << RESET
            << std::endl;

  list_stack.pop_back();

  std::cout << "Size after pop: " << GREEN << list_stack.size() << RESET
            << std::endl;

  list_stack.push_back(3);
  list_stack.push_back(5);
  list_stack.push_back(737);
  //[...]
  list_stack.push_back(0);

  std::list<int>::iterator lit = list_stack.begin();
  std::list<int>::iterator lite = list_stack.end();

  ++lit;
  --lit;

  std::cout << CYAN << "List content (bottom to top):" << RESET << std::endl;
  while (lit != lite) {
    std::cout << *lit << std::endl;
    ++lit;
  }

  std::cout << YELLOW
            << "\n========== 3. REVERSE ITERATOR TEST (MutantStack) =========="
            << RESET << std::endl;

  std::cout << CYAN
            << "Stack content (top to bottom using rbegin/rend):" << RESET
            << std::endl;
  MutantStack<int>::reverse_iterator rit = mstack.rbegin();
  MutantStack<int>::reverse_iterator rite = mstack.rend();

  while (rit != rite) {
    std::cout << *rit << std::endl;
    ++rit;
  }

  std::cout << YELLOW
            << "==========================================================\n"
            << RESET << std::endl;

  return 0;
}
