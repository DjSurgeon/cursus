/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:36:27 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 23:59:05 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include <string>
# define MATERIAS 4

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	virtual ~MateriaSource();
	virtual void			learnMateria(AMateria* materia);
	virtual AMateria*		createMateria(const std::string& type);
private:
	AMateria*	_templates[MATERIAS];
};

#endif