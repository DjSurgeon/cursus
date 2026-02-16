/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:55:02 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 23:13:08 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :
				_name("Default AForm"),
				_isSigned(false),
				_signGrade(42),
				_executeGrade(42)
{
}

AForm::AForm(const std::string& name, const int signGrade, const int executeGrade) :
				_name(name),
				_isSigned(false),
				_signGrade(signGrade),
				_executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& src) :
				_name(src._name),
				_isSigned(src._isSigned),
				_signGrade(src._signGrade),
				_executeGrade(src._executeGrade)
{
}

AForm& AForm::operator=(const AForm& src)
{
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return *this;
}

AForm::~AForm()
{
}

const std::string	AForm::getName() const
{
	return _name;
}

bool	AForm::getIsSigned() const
{
	return _isSigned;
}

int	AForm::getSignGrade() const
{
	return _signGrade;
}

int	AForm::getExecuteGrade() const
{
	return _executeGrade;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char * AForm::FormNotSigned::what() const throw()
{
	return "Form is not signed.";
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
	{
		throw AForm::GradeTooLowException();
	}
	else
		this->_isSigned = true;
}

void	AForm::execute(const Bureaucrat& bureaucrat) const
{
	if (this->getIsSigned() == false)
	{
		throw AForm::FormNotSigned();
	}
	if (this->getExecuteGrade() < bureaucrat.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
	this->executeAction();
}

std::ostream& operator<<(std::ostream& output, const AForm& form)
{
	output << form.getName() << " has sign grade: " << form.getSignGrade()
	<< " and has execute grade: " << form.getExecuteGrade()
	<< " and signed state is: " << form.getIsSigned()
	<< std::endl;
	return output;
}