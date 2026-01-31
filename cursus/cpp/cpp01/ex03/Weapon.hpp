/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:07:46 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 09:10:43 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

/// @brief Represents a weapon with a specific type string.
class Weapon
{
public:
	Weapon(const std::string& type);
	~Weapon();
	const std::string&	getType() const;
	void				setType(const std::string& typeWeapon);
private:
	std::string _type;
};

#endif
