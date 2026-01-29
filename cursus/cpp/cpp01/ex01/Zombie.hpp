/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serjimen <serjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:52:21 by sergio            #+#    #+#             */
/*   Updated: 2026/01/29 12:45:26 by serjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
public:
	Zombie();
	Zombie(const std::string&	zombieName);
	~Zombie();
	void		announce() const;
	void		setName(const std::string& name);
private:
	std::string	_name;
};

Zombie*		zombieHorde(int n, std::string name);

#endif
