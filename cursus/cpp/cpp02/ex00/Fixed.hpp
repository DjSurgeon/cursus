/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:45:04 by sergio            #+#    #+#             */
/*   Updated: 2026/02/06 13:45:21 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _FIXED_HPP_
# define _FIXED_HPP_

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int					getRawBits (void) const;
	void				setRawBits(int const raw);
private:
	int					_fixedValue;
	static const int	_fractionalBits = 8;
};

#endif
