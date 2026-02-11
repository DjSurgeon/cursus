/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:41:45 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 10:44:52 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* generic = new Animal();
	const Animal* odie = new Dog();
	const Animal* garfield = new Cat();

	std::cout << odie->getType() << std::endl;
	std::cout << garfield->getType() << std::endl;

	generic->makeSound();
	odie->makeSound();
	garfield->makeSound();

	std::cout << "--- WRONG ANIMAL TEST ---" << std::endl;
	const WrongAnimal* wrong = new WrongCat();
	wrong->makeSound();

	delete generic;
	delete odie;
	delete garfield;
	delete wrong;

	return 0;
}