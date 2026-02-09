/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:58:06 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 10:57:14 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedValue(other._fixedValue)
{
	std::cout << "Copy constructor called" << std::endl;
	// *this = other;
}

Fixed::Fixed(const int value)
{
	_fixedValue = value << _fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	_fixedValue = (int)roundf(value * (1 << _fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
//		this->_fixedValue = other.getRawBits();
		this->_fixedValue = (other._fixedValue);
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedValue;
}

void	Fixed::setRawBits(int const raw)
{
	_fixedValue = raw;
}

int	Fixed::toInt(void) const
{
	return _fixedValue >> _fractionalBits;
}

float	Fixed::toFloat(void) const
{
	return (float)_fixedValue / (float)(1 << _fractionalBits);
}

std::ostream & operator<<(std::ostream & output, Fixed const & value)
{
	output << value.toFloat();
	return output;
}
