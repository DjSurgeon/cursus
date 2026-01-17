/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:12:54 by sergio            #+#    #+#             */
/*   Updated: 2026/01/17 19:07:21 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::set_first(const std::string& first_name)
{
	_first_name = first_name;
}

void	Contact::set_last(const std::string& last_name)
{
	_last_name = last_name;
}

void	Contact::set_nick(const std::string& nickname)
{
	_nickname = nickname;
}

void	Contact::set_phone(const std::string& phone_number)
{
	_phone_number = phone_number;
}

void	Contact::set_dark(const std::string& darkest_secret)
{
	_darkest_secret = darkest_secret;
}

std::string	Contact::get_first() const
{
	return (_first_name);
}

std::string	Contact::get_last() const
{
	return (_last_name);
}

std::string	Contact::get_nick() const
{
	return (_nickname);
}
