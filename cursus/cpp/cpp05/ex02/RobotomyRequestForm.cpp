/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:43:14 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 23:01:38 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
			AForm("Robotomy Request Form", 72, 45),
			_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
			AForm(src),
			_target(src._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "*** (Drilling Noises) ***" << std::endl;
	std::cout << "*** rrRrRRRrRRrrRRR ***" << std::endl;
	std::cout << "*** PPPPppppPPpPpPp ***" << std::endl;
	std::cout << "*** RRrrrrrrRRrRRrr ***" << std::endl;
	std::cout << "*** BbbbBBbBBbBBBbB ***" << std::endl;
	if (rand() % 2)
	{
		std::cout << _target << " has been robotomized." << std::endl;
	}
	else
		std::cout << "The robotomized system failed." << std::endl;
}
