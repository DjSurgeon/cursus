/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:10:30 by sergio            #+#    #+#             */
/*   Updated: 2026/01/30 23:36:31 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << "Memory address variable: " << &str << std::endl;
	std::cout << "Memory address pointer: " << stringPTR << std::endl;
	std::cout << "Memory address reference: " << &stringREF << std::endl;

	std::cout << "Value variable: " << str << std::endl;
	std::cout << "Value pointer: " << *stringPTR << std::endl;
	std::cout << "Value reference: " << stringREF << std::endl;

	return (0);
}