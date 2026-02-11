/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:30:30 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 22:50:24 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter();
	virtual const std::string&	getName() const = 0;
	virtual void				equip(AMateria* materia) = 0;
	virtual void				unequip(int index) = 0;
	virtual void				use(int index, ICharacter& target) = 0;
};

#endif