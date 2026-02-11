/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:41:01 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 20:28:18 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria
{
public:
	AMateria(const std::string& type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();
	const std::string&		getType() const;
	virtual AMateria*		clone() const = 0;
	virtual void			use(ICharacter& target);
protected:
	std::string				_type;
};

#endif