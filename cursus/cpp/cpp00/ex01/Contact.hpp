/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:04:17 by sergio            #+#    #+#             */
/*   Updated: 2026/01/26 18:37:28 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

/// @brief Represents a single phonebook contact with personal details.
class Contact
{
public:
	Contact();
	~Contact();
	void		setFirstName(const std::string& firstName);
	void		setLastName(const std::string& lastName);
	void		setNickName(const std::string& nickName);
	void		setPhoneNumber(const std::string& phoneNumber);
	void		setDarkestSecret(const std::string& darkestSecret);
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickName() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

#endif
