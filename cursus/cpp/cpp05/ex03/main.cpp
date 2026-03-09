/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:41:22 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 23:35:28 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat boss("Big Boss", 1);

	std::cout << "--- TEST 1: ROBOTOMY ---" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n--- TEST 2: SHRUBBERY ---" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n--- TEST 3: PARDON ---" << std::endl;
	rrf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n--- TEST 4: INVALID FORM ---" << std::endl;
	rrf = someRandomIntern.makeForm("unknown form", "Nobody");
	if (rrf)
	{
		delete rrf;
	}

	return 0;
}
