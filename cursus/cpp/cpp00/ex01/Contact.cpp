/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:12:54 by sergio            #+#    #+#             */
/*   Updated: 2026/01/26 18:41:27 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/// @brief Constructor
Contact::Contact()
{
}

/// @brief Destructor
Contact::~Contact()
{
}

/// === SETTERS ===
void	Contact::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName)
{
	_lastName = lastName;
}

void	Contact::setNickName(const std::string& nickName)
{
	_nickName = nickName;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	_darkestSecret = darkestSecret;
}

/// === GETTERS ===
std::string	Contact::getFirstName() const
{
	return (_firstName);
}

std::string	Contact::getLastName() const
{
	return (_lastName);
}

std::string	Contact::getNickName() const
{
	return (_nickName);
}

std::string	Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}