/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:41:22 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 23:26:19 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	Bureaucrat boss("Big Boss", 1);
	Bureaucrat middle("Manager", 50);
	Bureaucrat intern("Intern", 148);

	// TEST 1
	try
	{
		ShrubberyCreationForm shrub("Garden");

		std::cout << "Attempt 1 (Intern signs): ";
		intern.signForm(shrub);

		std::cout << "Attempt 2 (Intern promoted & signs): " << std::endl;
		intern.incrementGrade();
		intern.incrementGrade();
		intern.incrementGrade();
		intern.signForm(shrub);

		std::cout << "Attempt 3 (Intern executes): ";
		intern.executeForm(shrub);

		std::cout << "Attempt 4 (Boss executes): " << std::endl;
		boss.executeForm(shrub);
	}
	catch (std::exception &e) 
	{ 
		std::cout << e.what() << std::endl; 
	}

	// TEST 2
	try
	{
		RobotomyRequestForm robot("Bender");
		
		boss.signForm(robot);

		std::cout << "Executing 4 times to check randomness:" << std::endl;
		boss.executeForm(robot);
		boss.executeForm(robot);
		boss.executeForm(robot);
		boss.executeForm(robot);
	}
	catch (std::exception &e)
	{ 
		std::cout << e.what() << std::endl;
	}

	// TEST 3
	try
	{
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << "Manager tries to sign: ";
		middle.signForm(pardon);

		std::cout << "Boss signs: " << std::endl;
		boss.signForm(pardon);

		std::cout << "Manager tries to execute: ";
		middle.executeForm(pardon);

		std::cout << "Boss executes: " << std::endl;
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{ 
		std::cout << e.what() << std::endl;
	}

	// TEST 4
	try
	{
		ShrubberyCreationForm unsignedForm("Forest");
		
		std::cout << "Boss tries to execute unsigned form: ";
		boss.executeForm(unsignedForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}