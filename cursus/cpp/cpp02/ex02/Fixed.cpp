/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:58:06 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 12:42:56 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedValue(0)
{
}

Fixed::Fixed(const Fixed& other) : _fixedValue(other._fixedValue)
{
}

Fixed::Fixed(const int value)
{
	_fixedValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_fixedValue = (int)roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_fixedValue = (other._fixedValue);
	return *this;
}

bool	Fixed::operator>(const Fixed& value) const
{
	return this->getRawBits() > value.getRawBits();
}

bool	Fixed::operator<(const Fixed& value) const
{
	return this->getRawBits() < value.getRawBits();
}

bool	Fixed::operator>=(const Fixed& value) const
{
	return this->getRawBits() >= value.getRawBits();
}

bool	Fixed::operator<=(const Fixed& value) const
{
	return this->getRawBits() <= value.getRawBits();
}

bool	Fixed::operator==(const Fixed& value) const
{
	return this->getRawBits() == value.getRawBits();
}

bool	Fixed::operator!=(const Fixed& value) const
{
	return this->getRawBits() != value.getRawBits();
}

Fixed Fixed::operator+(const Fixed& value) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() + value.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed& value) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() - value.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed& value) const
{
	Fixed	result;
	long long temp = (long long)this->getRawBits() * (long long)value.getRawBits();
	result.setRawBits(temp >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& value) const
{
	Fixed	result;
	long long temp = ((long long)this->getRawBits() << _fractionalBits) / value.getRawBits();
	result.setRawBits(temp);
	return result;
}

Fixed& Fixed::operator++(void)
{
	this->_fixedValue++;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->_fixedValue--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fixedValue++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixedValue--;
	return temp;
}

Fixed&	Fixed::min(Fixed& value1, Fixed& value2)
{
	if (value1 < value2)
		return (value1);
	return (value2);
}
const Fixed&	Fixed::min(const Fixed& value1, const Fixed& value2)
{
	if (value1 < value2)
		return (value1);
	return (value2);
}
Fixed&	Fixed::max(Fixed& value1, Fixed& value2)
{
	if (value1 > value2)
		return (value1);
	return (value2);
}
const Fixed&	Fixed::max(const Fixed& value1, const Fixed& value2)
{
	if (value1 > value2)
		return (value1);
	return (value2);
}

int	Fixed::getRawBits(void) const
{
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
