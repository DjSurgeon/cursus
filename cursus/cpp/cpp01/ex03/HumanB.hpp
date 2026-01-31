/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:56:50 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 09:35:25 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

/// @brief Represents a human that MAY or MAY NOT have a weapon.
class HumanB
{
public:
	HumanB(const std::string& name);
	~HumanB();
	void				attack() const;
	void				setWeapon(Weapon& weapon);
private:
	std::string	_name;
	Weapon*		_weapon;
};

#endif