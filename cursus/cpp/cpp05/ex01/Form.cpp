/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:55:02 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 18:11:31 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
				_name("Default Form"),
				_isSigned(false),
				_signGrade(42),
				_executeGrade(42)
{
}

Form::Form(const std::string& name, const int signGrade, const int executeGrade) :
				_name(name),
				_isSigned(false),
				_signGrade(signGrade),
				_executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& src) :
				_name(src._name),
				_isSigned(src._isSigned),
				_signGrade(src._signGrade),
				_executeGrade(src._executeGrade)
{
}

Form& Form::operator=(const Form& src)
{
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return *this;
}

Form::~Form()
{
}

const std::string	Form::getName() const
{
	return _name;
}

bool	Form::getIsSigned() const
{
	return _isSigned;
}

int	Form::getSignGrade() const
{
	return _signGrade;
}

int	Form::getExecuteGrade() const
{
	return _executeGrade;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
	{
		throw Form::GradeTooLowException();
	}
	else
		this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& output, const Form& form)
{
	output << form.getName() << " has sign grade: " << form.getSignGrade()
	<< " and has execute grade: " << form.getExecuteGrade()
	<< " and signed state is : " << form.getIsSigned()
	<< std::endl;
	return output;
}