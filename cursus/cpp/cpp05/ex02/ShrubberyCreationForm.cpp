/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:53:25 by sergio            #+#    #+#             */
/*   Updated: 2026/02/16 22:48:58 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
				AForm("Shrubbery Creation Form", 145, 137),
				_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :
				AForm(src),
				_target(src._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::executeAction() const
{
	std::string		filename = _target + "_shrubbery";
	std::ofstream	outfile(filename.c_str());
	if (outfile.is_open())
	{
		outfile << "       _-_" << std::endl;
		outfile << "    /~~   ~~\\" << std::endl;
		outfile << " /~~         ~~\\" << std::endl;
		outfile << " {               }" << std::endl;
		outfile << " \\  _-     -_  /" << std::endl;
		outfile << "   ~  \\\\ //  ~" << std::endl;
		outfile << "_- -   | | _- _" << std::endl;
		outfile << "  _ -  | |   -_" << std::endl;
		outfile << "      // \\\\" << std::endl;
		outfile.close();
	}
	else
		std::cerr << "Imposible create or open the file" << std::endl;
}