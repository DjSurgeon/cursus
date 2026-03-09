/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:00:00 by sergio            #+#    #+#             */
/*   Updated: 2026/03/09 10:00:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
	(void)src;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return *this;
}

Intern::~Intern()
{
}

/**
 * Helper functions to create specific forms.
 * These are called via the jump table.
 */
static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	// Define the available form names
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// Define an array of function pointers matching the names
	// AForm* (*creators[])(const std::string&) is an array of pointers to static functions
	AForm* (*creators[])(const std::string&) = {
		&createShrubbery,
		&createRobotomy,
		&createPardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Error: Intern cannot create form '" << formName << "' because it doesn't exist." << std::endl;
	return NULL;
}
