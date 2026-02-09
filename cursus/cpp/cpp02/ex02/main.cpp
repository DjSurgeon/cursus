/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:04:23 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 12:52:51 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
/* 
	// =========================================================================
	// 1. ARITHMETIC OPERATORS TESTS
	std::cout << ">>> RUNNING ARITHMETIC TESTS" << std::endl;

	Fixed x(10);
	Fixed y(2.5f);

	std::cout << "Values: x = " << x << ", y = " << y << std::endl;

	// Addition (+)
	Fixed sum = x + y;
	std::cout << "Sum (x + y): " << sum << " (Expected: 12.5)" << std::endl;

	// Subtraction (-)
	Fixed diff = x - y;
	std::cout << "Difference (x - y): " << diff << " (Expected: 7.5)" << std::endl;

	// Multiplication (*)
	Fixed prod = x * y;
	std::cout << "Product (x * y): " << prod << " (Expected: 25)" << std::endl;

	// Division (/)
	Fixed div = x / y;
	std::cout << "Division (x / y): " << div << " (Expected: 4)" << std::endl;

	// =========================================================================
	// 2. COMPARISON OPERATORS TESTS
	std::cout << ">>> RUNNING COMPARISON TESTS" << std::endl;

	Fixed z(10);
	std::cout << "Values: x = " << x << ", y = " << y << ", z = " << z <<std::endl;
	std::cout << "Is x > y?  " << (x > y ? "Yes" : "No") << std::endl;
	std::cout << "Is x < y?  " << (x < y ? "Yes" : "No") << std::endl;
	std::cout << "Is x >= z? " << (x >= z ? "Yes" : "No") << std::endl;
	std::cout << "Is x <= y? " << (x <= y ? "Yes" : "No") << std::endl;
	std::cout << "Is x == z? " << (x == z ? "Yes" : "No") << std::endl;
	std::cout << "Is x != y? " << (x != y ? "Yes" : "No") << std::endl;

	// =========================================================================
	// 3. MIN / MAX STATIC FUNCTIONS TESTS
    std::cout << ">>> RUNNING MIN/MAX TESTS" << std::endl;

	Fixed small(3.5f);
	Fixed big(9.1f);

	// Testing non-const min/max
	std::cout << "Min(3.5, 9.1): " << Fixed::min(small, big) << std::endl;
	std::cout << "Max(3.5, 9.1): " << Fixed::max(small, big) << std::endl;

	// Testing const min/max
	Fixed const c_small(1.1f);
	Fixed const c_big(8.8f);

	std::cout << "Const Min(1.1, 8.8): " << Fixed::min(c_small, c_big) << std::endl;
	std::cout << "Const Max(1.1, 8.8): " << Fixed::max(c_small, c_big) << std::endl;
 */
	return 0;
}
