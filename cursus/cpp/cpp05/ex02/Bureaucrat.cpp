/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:05:16 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 20:27:56 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(42)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Maximum is 1.";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Minimum is 150.";
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this); 
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureau)
{
	output << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << "."
	<< std::endl;
	return output;
}
