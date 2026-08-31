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

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <set>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

int main()
{
    // ---------------------------------------------------------
    // 1. SUBJECT TEST
    // ---------------------------------------------------------
    std::cout << YELLOW << "\n========== 1. SUBJECT TEST ==========" << RESET << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest Span: " << GREEN << sp.shortestSpan() << RESET << " (Expected: 2)" << std::endl;
        std::cout << "Longest Span:  " << GREEN << sp.longestSpan() << RESET << " (Expected: 14)" << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    // ---------------------------------------------------------
    // 2. EXCEPTIONS TEST
    // ---------------------------------------------------------
    std::cout << YELLOW << "\n========== 2. EXCEPTIONS TEST ==========" << RESET << std::endl;
    
    std::cout << CYAN << "[Test] Attempting to calculate span with 0 elements..." << RESET << std::endl;
    try {
        Span emptySpan(5);
        emptySpan.shortestSpan();
    } catch (std::exception &e) {
        std::cout << GREEN << "Caught correctly: " << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << "\n[Test] Attempting to calculate span with 1 element..." << RESET << std::endl;
    try {
        Span oneSpan(5);
        oneSpan.addNumber(42);
        oneSpan.longestSpan();
    } catch (std::exception &e) {
        std::cout << GREEN << "Caught correctly: " << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << "\n[Test] Attempting to add element to full Span..." << RESET << std::endl;
    try {
        Span fullSpan(2);
        fullSpan.addNumber(1);
        fullSpan.addNumber(2);
        fullSpan.addNumber(3); // Should throw
    } catch (std::exception &e) {
        std::cout << GREEN << "Caught correctly: " << e.what() << RESET << std::endl;
    }

    // ---------------------------------------------------------
    // 3. STRESS TEST (100,000 ELEMENTS)
    // ---------------------------------------------------------
    std::cout << YELLOW << "\n========== 3. STRESS TEST (100,000 ELEMENTS) ==========" << RESET << std::endl;
    
    Span megaSpan(100000);
    std::vector<int> randomNumbers;
    
    std::cout << "Generating 100,000 random numbers [0, INT_MAX]..." << std::endl;
    std::srand(std::time(NULL));
    for (int i = 0; i < 100000; i++) {
        randomNumbers.push_back(std::rand() % INT_MAX);
    }
    
    std::cout << "Adding numbers via Iterator Range..." << std::endl;
    try {
        megaSpan.addNumber(randomNumbers.begin(), randomNumbers.end());
        std::cout << GREEN << "Numbers added successfully!" << RESET << std::endl;
        
        std::cout << "Calculating spans..." << std::endl;
        std::cout << "Shortest Span: " << GREEN << megaSpan.shortestSpan() << RESET << std::endl;
        std::cout << "Longest Span:  " << GREEN << megaSpan.longestSpan() << RESET << std::endl;
        
    } catch (std::exception &e) {
        std::cout << RED << "Error during stress test: " << e.what() << RESET << std::endl;
    }
    
    std::cout << YELLOW << "=======================================================\n" << RESET << std::endl;

    // ---------------------------------------------------------
    // 4. STRESS TEST CON SET (100,000 UNIQUE ELEMENTS)
    // ---------------------------------------------------------
    std::cout << YELLOW << "\n========== 4. STRESS TEST (100,000 UNIQUE ELEMENTS SET) ==========" << RESET << std::endl;
    
    Span megaSetSpan(100000);
    std::set<int> uniqueNumbers;
    
    std::cout << "Generating 100,000 UNIQUE random numbers [0, INT_MAX]..." << std::endl;
    while (uniqueNumbers.size() < 100000) {
        uniqueNumbers.insert(std::rand() % INT_MAX);
    }
    
    std::cout << "Adding unique numbers via Set Iterator Range..." << std::endl;
    try {
        megaSetSpan.addNumber(uniqueNumbers.begin(), uniqueNumbers.end());
        std::cout << GREEN << "Numbers added successfully from std::set!" << RESET << std::endl;
        
        std::cout << "Calculating spans..." << std::endl;
        std::cout << "Shortest Span: " << GREEN << megaSetSpan.shortestSpan() << RESET << std::endl;
        std::cout << "Longest Span:  " << GREEN << megaSetSpan.longestSpan() << RESET << std::endl;
        
    } catch (std::exception &e) {
        std::cout << RED << "Error during stress test with set: " << e.what() << RESET << std::endl;
    }
    
    std::cout << YELLOW << "=======================================================\n" << RESET << std::endl;

    return 0;
}
