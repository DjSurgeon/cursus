/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:16:28 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 13:52:08 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _xValue(0), _yValue(0)
{
}

Point::Point(float const xValue, float const yValue) : _xValue(xValue), _yValue(yValue)
{
}

Point::Point(const Point& other) : _xValue(other._xValue), _yValue(other._yValue)
{

}
Point&	Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

Point::~Point()
{
}

Fixed	Point::getX() const
{
	return _xValue ;
}

Fixed	Point::getY() const
{
	return _yValue ;
}
