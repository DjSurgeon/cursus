/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:07:08 by sergio            #+#    #+#             */
/*   Updated: 2026/02/09 14:12:10 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
/*
	// Definimos un triángulo simple
	//       (10, 30) B
	//         /  \
	//        /    \
	// A (0, 0)----(20, 0) C
*/
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);

	Point p1(15, 10);
	std::cout << "Punto dentro (10, 10): " << bsp(a, b, c, p1) << std::endl;

	Point p2(30, 10);
	std::cout << "Punto fuera (30, 10):  " << bsp(a, b, c, p2) << std::endl;

	Point p3(10, 0);
	std::cout << "Punto borde (10, 0):   " << bsp(a, b, c, p3) << std::endl;

	Point p4(0, 0);
	std::cout << "Punto vértice (0, 0):  " << bsp(a, b, c, p4) << std::endl;

	return 0;
}