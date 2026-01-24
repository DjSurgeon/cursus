/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:04:17 by sergio            #+#    #+#             */
/*   Updated: 2026/01/24 17:01:36 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
public:
	Contact();
	~Contact();
	void		set_first(const std::string& first_name);
	void		set_last(const std::string& last_name);
	void		set_nick(const std::string& nickname);
	void		set_phone(const std::string& phone_number);
	void		set_dark(const std::string& darkest_secret);
	std::string	get_first() const;
	std::string	get_last() const;
	std::string	get_nick() const;
};

#endif
