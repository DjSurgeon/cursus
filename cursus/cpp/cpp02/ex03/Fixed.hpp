/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:45:04 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 12:20:15 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int value);
	Fixed(const float value);
	Fixed& operator=(const Fixed& other);
	bool operator>(const Fixed& value) const;
	bool operator<(const Fixed& value) const;
	bool operator>=(const Fixed& value) const;
	bool operator<=(const Fixed& value) const;
	bool operator==(const Fixed& value) const;
	bool operator!=(const Fixed& value) const;
	Fixed operator+(const Fixed& value) const;
	Fixed operator-(const Fixed& value) const;
	Fixed operator*(const Fixed& value) const;
	Fixed operator/(const Fixed& value) const;
	Fixed& operator++(void);
	Fixed& operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed&			min(Fixed& value1, Fixed& value2);
	static const Fixed&		min(const Fixed& value1, const Fixed& value2);
	static Fixed&			max(Fixed& value1, Fixed& value2);
	static const Fixed&		max(const Fixed& value1, const Fixed& value2);
	~Fixed();
	int						getRawBits (void) const;
	void					setRawBits(int const raw);
	int						toInt(void) const;
	float					toFloat(void) const;
private:
	int						_fixedValue;
	static const int		_fractionalBits = 8;
};

std::ostream & operator<<(std::ostream & output, Fixed const & value);

#endif
