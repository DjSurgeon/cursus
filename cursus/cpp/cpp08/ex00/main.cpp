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
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

// Colores para la salida
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

template <typename Container>
void testContainer(Container& c, int valueToFind, const std::string& containerName) {
    std::cout << CYAN << "Testing " << containerName << " - Searching for: " << valueToFind << RESET << std::endl;
    try {
        typename Container::iterator it = easyfind(c, valueToFind);
        std::cout << GREEN << "Success! Element " << *it << " found." << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
}

int main() {
    std::cout << YELLOW << "\n========== TEST: STD::VECTOR ==========" << RESET << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i)
        vec.push_back(i * 10); // 0, 10, 20, 30, 40
        
    testContainer(vec, 20, "std::vector");
    testContainer(vec, 42, "std::vector");

    std::cout << YELLOW << "\n========== TEST: STD::LIST ============" << RESET << std::endl;
    std::list<int> lst;
    for (int i = 0; i < 5; ++i)
        lst.push_back(i * 5); // 0, 5, 10, 15, 20
        
    testContainer(lst, 0, "std::list (first element)");
    testContainer(lst, 20, "std::list (last element)");
    testContainer(lst, 99, "std::list");

    std::cout << YELLOW << "\n========== TEST: STD::DEQUE ===========" << RESET << std::endl;
    std::deque<int> deq;
    for (int i = 0; i < 5; ++i)
        deq.push_front(i); // 4, 3, 2, 1, 0
        
    testContainer(deq, 3, "std::deque");
    testContainer(deq, -1, "std::deque");

    std::cout << YELLOW << "\n========== TEST: EMPTY CONTAINER ======" << RESET << std::endl;
    std::vector<int> emptyVec;
    testContainer(emptyVec, 0, "Empty std::vector");

    return 0;
}
