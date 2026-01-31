/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 01:09:36 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 09:13:26 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		Weapon sword = Weapon("Sword");
		HumanA bob("Bob", sword);
		bob.attack();
		sword.setType("Big sword");
		bob.attack();
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(sword);
		jim.attack();
		sword.setType("Giant Sword!!");
		jim.attack();
		bob.attack();
	}
	return (0);
}