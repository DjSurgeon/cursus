/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:27:54 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 03:02:12 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon& type);
	~HumanA();
	void	attack() const;
	const std::string& getName() const;
private:
	std::string	_name;
	Weapon&		_type;
};

#endif
