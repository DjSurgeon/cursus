/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:59:42 by serjimen          #+#    #+#             */
/*   Updated: 2026/02/11 12:11:29 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
public:
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();
	virtual void			makeSound() const = 0;
	std::string				getType() const;
protected:
	std::string				_type;
};

#endif
