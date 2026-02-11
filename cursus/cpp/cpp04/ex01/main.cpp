/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:41:45 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 12:15:15 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define N_ANIMALS 4

int main()
{
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Test 1: Polymorphism" << std::endl;

	const Animal* animals[N_ANIMALS];

	std::cout << "--> Create Animals..." << std::endl;
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		if (i < N_ANIMALS / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n--> Delete animals..." << std::endl;
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		delete animals[i];
	}

	std::cout << "\n-------------------------------------------------------" << std::endl;
	std::cout << "Test 2: DEEP COPY" << std::endl;

	std::cout << "--> Create Dog:" << std::endl;
	Dog* originalDog = new Dog();

	std::cout << "\n--> Create Dog Copy" << std::endl;
	Dog* copyDog = new Dog(*originalDog);

	std::cout << "\n--> Delete ORIGINAL:" << std::endl;
	delete originalDog; 

	std::cout << "\n--> Delete COPY:" << std::endl;
	delete copyDog; 

	std::cout << "\n-------------------------------------------------------" << std::endl;
	std::cout << "Test 3: DEEP COPY & IDEAS" << std::endl;

	Cat* garfield = new Cat();

	garfield->setIdea(0, "... I love lasagna ...");
	std::cout << garfield->getIdea(0) << std::endl;

	Cat* telma = new Cat(*garfield);
	std::cout << telma->getIdea(0) << std::endl;

	telma->setIdea(0, "... Wrong!! ... I love fish ...");

	std::cout << garfield->getIdea(0) << std::endl;
	std::cout << telma->getIdea(0) << std::endl;

	delete garfield;
	delete telma;

	return 0;
}