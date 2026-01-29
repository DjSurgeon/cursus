/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:52:21 by sergio            #+#    #+#             */
/*   Updated: 2026/01/29 11:32:43 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

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
