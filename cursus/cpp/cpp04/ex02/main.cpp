/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:41:45 by sergio            #+#    #+#             */
/*   Updated: 2026/02/11 12:20:12 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	// AAnimal* meta = new AAnimal(); // <--- ERROR

	AAnimal* dog = new Dog();
	AAnimal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	return 0;
}