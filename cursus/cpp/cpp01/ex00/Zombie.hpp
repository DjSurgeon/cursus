/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:52:21 by sergio            #+#    #+#             */
/*   Updated: 2026/01/30 23:12:38 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

/// @brief Represents a Zombie with a name and the ability to announce itself.
class Zombie
{
public:
	Zombie(const std::string& zombieName);
	~Zombie();
	void		announce() const;
private:
	std::string	_name;
};

Zombie*		newZombie(const std::string& name);
void		randomChump(const std::string& name);

#endif
