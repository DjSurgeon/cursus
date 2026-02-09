/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:16:16 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 13:51:07 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(float const xValue, float const yValue);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	Fixed			getX() const;
	Fixed			getY() const;
private:
	Fixed const		_xValue;
	Fixed const		_yValue;
};

#endif