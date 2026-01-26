/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:50:09 by sergio            #+#    #+#             */
/*   Updated: 2026/01/26 19:04:45 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <cstdlib>

/// @brief Manages the phonebook with a maximum of 8 contacts.
class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void		addContact();
	void		displayData();
private:
	Contact		_contacts[8];
	size_t		_index;
	size_t		_counter;
	std::string	_setData(const std::string& input);
	void		_searchContact();
	std::string	_truncate(const std::string& info);
	void		_displayContact(size_t index);
	void		_displayAllContactInfo(size_t index);
};

#endif
