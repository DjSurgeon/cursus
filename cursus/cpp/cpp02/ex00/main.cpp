/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:54:00 by sergio            #+#    #+#             */
/*   Updated: 2026/02/06 14:14:50 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// Fixed a;
	// a.setRawBits(42);
	// Fixed b(a);
	// std::cout << "b: " << b.getRawBits() << std::endl;
	// b.setRawBits(19);
	// std::cout << "b: " << b.getRawBits() << std::endl;
	// std::cout << "a: " << a.getRawBits() << std::endl;
	// a = b;
	// std::cout << "b: " << b.getRawBits() << std::endl;
	// std::cout << "a: " << a.getRawBits() << std::endl;
	// Fixed c;
	// c.setRawBits(-10);
	// b = c;
	// std::cout << "b: " << b.getRawBits() << std::endl;

	return (0);
}