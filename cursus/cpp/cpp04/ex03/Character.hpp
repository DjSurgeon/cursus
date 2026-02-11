/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:41:58 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 23:17:11 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>
# define SLOTS 4

class Character : public ICharacter
{
public:
	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	virtual ~Character();
	virtual const std::string&	getName() const;
	virtual void				equip(AMateria* materia);
	virtual void				unequip(int index);
	virtual void				use(int index, ICharacter& target);
private:
	std::string					_name;
	AMateria*					_inventory[SLOTS];
};

#endif