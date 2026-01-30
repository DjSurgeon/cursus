/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:33:33 by sergio            #+#    #+#             */
/*   Updated: 2026/01/30 23:12:13 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/// @brief Creates a Zombie on the Heap.
/// @param name The name for the new zombie.
/// @return A pointer to the newly allocated Zombie.
Zombie*	newZombie(const std::string& name)
{
	Zombie* hannah = new Zombie(name);
	return (hannah);
}
