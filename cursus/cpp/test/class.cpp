/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:29:40 by sergio            #+#    #+#             */
/*   Updated: 2026/01/10 01:06:31 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Square
{
private:
	int		height;
	int		width;
	size_t	id;
	const size_t new_id;
public:
	Square(int h, int w, size_t id, const size_t new_id_val);
	~Square();

	void show()
	{
		std::cout << "Square[" << id << "] (new_id: " << new_id << "): " << height << " x " << width << std::endl;
	}
};

Square::Square(int h, int w, size_t i, const size_t new_id_val)
	: height(h), width(w), id(i), new_id(new_id_val)
{
	std::cout << "New square created... with id: " << id << " and new_id: " << new_id << std::endl;
}

Square::~Square()
{
	std::cout << "Square[" << id << "] destroyed..." << std::endl;
}

int	main(void)
{
	Square sq1(100, 150, 1, 11);
	sq1.show();
	Square sq2(100, 250, 2, 22);
	Square sq3(100, 350, 3, 33);

	return (0);
}