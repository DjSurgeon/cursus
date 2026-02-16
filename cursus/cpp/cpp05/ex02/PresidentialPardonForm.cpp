/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:04:59 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 22:58:42 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
			AForm("Presidential Pardon Form", 25, 5),
			_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src):
			AForm(src),
			_target(src._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << "The " << _target << " has been pardoned by Zaphod Beeblebox";
}