/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:35:30 by sergio            #+#    #+#             */
/*   Updated: 2026/02/12 00:12:59 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < MATERIAS; i++)
		this->_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (size_t i = 0; i < MATERIAS; i++)
	{
		if (other._templates[i] != NULL)
			this->_templates[i] = other._templates[i]->clone();
		else
			this->_templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < MATERIAS; i++)
		{
			if (this->_templates[i] != NULL)
			{
				delete this->_templates[i];
				this->_templates[i] = NULL;
			}
		}
		for (size_t i = 0; i < MATERIAS; i++)
		{
			if (other._templates[i] != NULL)
				this->_templates[i] = other._templates[i]->clone();
			else
				this->_templates[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < MATERIAS; i++)
	{
		if (this->_templates[i] != NULL)
			delete this->_templates[i];
	}
	
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return ;
	for (size_t i = 0; i < MATERIAS; i++)
	{
		if (this->_templates[i] == NULL)
		{
			this->_templates[i] = materia;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (size_t i = 0; i < MATERIAS; i++)
	{
		if (this->_templates[i] != NULL && _templates[i]->getType() == type)
			return this->_templates[i]->clone();
	}
	return NULL;
}