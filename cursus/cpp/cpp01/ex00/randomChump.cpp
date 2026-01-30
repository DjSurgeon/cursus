/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:37:49 by sergio            #+#    #+#             */
/*   Updated: 2026/01/30 23:12:45 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/// @brief Creates a Zombie on the Stack.
/// @param name The name for the temporary Zombie.
void	randomChump(const std::string& name)
{
	Zombie	bob(name);
	bob.announce();
}
