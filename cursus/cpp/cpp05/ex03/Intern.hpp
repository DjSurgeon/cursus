/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:00:00 by sergio            #+#    #+#             */
/*   Updated: 2026/03/09 10:00:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& src);
	Intern& operator=(const Intern& src);
	~Intern();

	AForm*	makeForm(const std::string& formName, const std::string& target);
};

#endif
