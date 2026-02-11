/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:58:15 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 20:31:11 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& other);
	Ice& operator=(const AMateria& other);
	virtual ~Ice();
	virtual AMateria*		clone() const;
	virtual void			use(ICharacter& target);
};

#endif