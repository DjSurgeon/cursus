/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:16:25 by sergio            #+#    #+#             */
/*   Updated: 2026/01/10 01:22:57 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Counter
{
private:
	int	number;
public:
	Counter(int i);
	~Counter();
	void	show()
	{
		std::cout << number << std::endl;
	}
	void	inc()
	{
		number++;
	}
	void	dec()
	{
		number--;
	}
};

Counter::Counter(int i) : number(i)
{
	std::cout << "Counter created..." << std::endl;
}

Counter::~Counter()
{
	std::cout << "Counter destroyed..." << std::endl;
}

int	main(void)
{
	Counter c(0);
	c.show();
	for (size_t i = 0; i < 10; i++)
	{
		c.inc();
	}
	c.dec();
	c.show(); // expect 9;

	return (0);
}