/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:05:10 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 14:06:56 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed calculate_cross_product(Point const a, Point const b, Point const p)
{
	return (b.getX() - a.getX()) * (p.getY() - a.getY()) - 
			(b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed val1 = calculate_cross_product(a, b, point);
	Fixed val2 = calculate_cross_product(b, c, point);
	Fixed val3 = calculate_cross_product(c, a, point);

	if (val1 > 0 && val2 > 0 && val3 > 0)
		return (true);
	if (val1 < 0 && val2 < 0 && val3 < 0)
		return (true);
	return (false);
}
