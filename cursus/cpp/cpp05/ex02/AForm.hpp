/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:54:35 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 20:21:27 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(const std::string& name, const int signGrade, const int executeGrade);
	AForm(const AForm& src);
	AForm& operator=(const AForm& src);
	virtual ~AForm();
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
	class FormNotSigned : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	void					beSigned(const Bureaucrat& bureaucrat);
	void					execute(const Bureaucrat& bureaucrat) const;
protected:
	virtual void			executeAction() const = 0;
private:
	const std::string		_name;
	bool					_isSigned;
	const int				_signGrade;
	const int				_executeGrade;
};

std::ostream& operator<<(std::ostream& output, const AForm& form);

#endif