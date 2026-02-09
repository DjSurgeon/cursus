/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:45:04 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 10:20:16 by sergio           ###   ########.fr       */
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
	~Fixed();
	int					getRawBits (void) const;
	void				setRawBits(int const raw);
	int					toInt(void) const;
	float				toFloat(void) const;
private:
	int					_fixedValue;
	static const int	_fractionalBits = 8;
};

std::ostream & operator<<(std::ostream & output, Fixed const & value);

#endif
