/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:27:54 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 09:19:42 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

/// @brief Represents a human that IS ALWAYS ARMED.
class HumanA
{
public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
	void	attack() const;
private:
	std::string	_name;
	Weapon&		_weapon;
};

#endif
