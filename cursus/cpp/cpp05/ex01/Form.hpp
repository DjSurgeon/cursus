/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:54:35 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 14:26:21 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
public:
	Form();
	Form(const std::string& name, const int signGrade, const int executeGrade);
	Form(const Form& src);
	Form& operator=(const Form& src);
	~Form();
	const std::string		getName() const;
	bool					getIsSigned() const;
	int						getSignGrade() const;
	int						getExecuteGrade() const;
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	void					beSigned(const Bureaucrat& bureaucrat);
private:
	const std::string		_name;
	bool					_isSigned;
	const int				_signGrade;
	const int				_executeGrade;
};

std::ostream& operator<<(std::ostream& output, const Form& form);

#endif