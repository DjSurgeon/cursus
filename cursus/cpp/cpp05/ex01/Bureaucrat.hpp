/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:05:04 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 14:07:16 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>

class Form;

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat& operator=(const Bureaucrat& src);
	~Bureaucrat();
	std::string				getName() const;
	int						getGrade() const;
	void					incrementGrade();
	void					decrementGrade();
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
	void					signForm(Form& form);
private:
	const std::string		_name;
	int						_grade;
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureau);

#endif