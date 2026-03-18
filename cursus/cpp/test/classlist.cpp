/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classlist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:29:40 by sergio            #+#    #+#             */
/*   Updated: 2026/01/10 01:13:26 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Square
{
private:
	int		height;
	int		width;
	size_t	id;
public:
	Square(int h, int w, size_t i);
	~Square();

	void show()
	{
		std::cout << "Square["<< id << "]: " << height << " x " << width << std::endl;
	}
};

Square::Square(int h, int w, size_t i) : height(h), width(w), id(i)
{
	std::cout << "New square created... with id: " << id << std::endl;
}

Square::~Square()
{
	std::cout << "Square["<< id << "] destroyed..." << std::endl;
}

int	main(void)
{
	Square sq1(100, 150, 1);
	sq1.show();
	Square sq2(100, 250, 2);
	Square sq3(100, 350, 3);

	return (0);
}