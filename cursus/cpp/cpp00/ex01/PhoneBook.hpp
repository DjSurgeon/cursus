/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:50:09 by sergio            #+#    #+#             */
/*   Updated: 2026/01/26 14:29:25 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact		_contacts[8];
	size_t		_index;
	size_t		_count;
	std::string	_set_data(const std::string& data);
	std::string	_truncate(const std::string& str);
	void		_display_contact(size_t index);
public:
	PhoneBook();
	~PhoneBook();
	void		add_contact();
	void		search_contact(int index);
	void		display_data();
};

#endif
