/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:33:14 by sergio            #+#    #+#             */
/*   Updated: 2026/02/12 00:19:13 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"
# include <string>

class IMateriaSource
{
public:
	virtual ~IMateriaSource();
	virtual void			learnMateria(AMateria* materia) = 0;
	virtual AMateria*		createMateria(const std::string& type) = 0;
};

#endif
