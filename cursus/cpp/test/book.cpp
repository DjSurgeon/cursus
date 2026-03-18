/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:15:46 by sergio            #+#    #+#             */
/*   Updated: 2026/01/16 23:43:39 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Book
{
private:
	std::string	_title;
	size_t		_pages;
public:
	Book(std::string, size_t pages);
	~Book();
	void	showBook();
};

Book::Book(std::string title, size_t pages) : _title(title), _pages(pages)
{
}

Book::~Book()
{
}

void	Book::showBook()
{
	std::cout << "Title: " << _title << ", Pages: " << _pages << std::endl;
}

int	main(void)
{
	Book elantris("Elantris", 786);
	elantris.showBook();
	return (0);
}
