/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:41:22 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 18:12:17 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main.cpp                                           :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: tu_usuario <tu_email@student.42.fr>        +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/02/16 14:00:00 by tu_usuario        #+#    #+#             */
/* Updated: 2026/02/16 14:00:00 by tu_usuario       ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "TEST 1" << std::endl;
	try
	{
		Bureaucrat boss("Big Boss", 1);
		std::cout << boss << std::endl;
		Form contract("Employment Contract", 50, 100);
		std::cout << "Status before signing: " << contract << std::endl;
		boss.signForm(contract);
		std::cout << "Status after signing: " << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "TEST 2" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		std::cout << intern << std::endl;
		Form secretDoc("Top Secret", 10, 10);
		std::cout << "Status before signing: " << secretDoc << std::endl;
		intern.signForm(secretDoc);
		std::cout << "Status after signing: " << secretDoc << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "TEST 3" << std::endl;
	try
	{
		Form impossible("Impossible Form", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "TEST 4" << std::endl;
	try
	{
		Form trash("Trash Form", 151, 150);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}