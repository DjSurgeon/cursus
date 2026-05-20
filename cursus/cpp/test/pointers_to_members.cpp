/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_to_members.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:45:00 by sergio            #+#    #+#             */
/*   Updated: 2026/05/18 12:45:00 by sergio           ###   ########.fr       */
/*                                                                            */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:45:00 by sergio            #+#    #+#             */
/*   Updated: 2026/05/18 12:45:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Harl
{
private:
	void debug(void) {
		std::cout << "DEBUG: I love having extra bacon on my burger!" << std::endl;
	}
	void info(void) {
		std::cout << "INFO: I cannot believe adding extra bacon costs more money." << std::endl;
	}
	void warning(void) {
		std::cout << "WARNING: I think I deserve some extra bacon for free." << std::endl;
	}
	void error(void) {
		std::cout << "ERROR: This is unacceptable! I want to speak to the manager." << std::endl;
	}

public:
	void complain(std::string level)
	{
		// 1. Declaración de un array de strings con los niveles
		std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

		// 2. RETO PRÁCTICO:
		// Aquí debemos declarar un array de punteros a funciones miembro de la clase Harl.
		// El tipo de los métodos privados es: void (Harl::*)(void)
		// TODO: Declara el array "methods" e inicialízalo con las direcciones de debug, info, warning y error.
		
		// void (Harl::*methods[])(void) = {
		//     // Coloca aquí los punteros...
		// };

		// 3. RETO PRÁCTICO:
		// Recorremos los niveles. Si coincide con "level", llamamos al método correspondiente.
		for (int i = 0; i < 4; i++)
		{
			if (levels[i] == level)
			{
				// TODO: Llama a la función miembro apuntada por "methods[i]" utilizando el objeto actual (*this)
				// Pista: Recuerda usar la sintaxis (this->*methods[i])() o (*this.*methods[i])()
				std::cout << "[Nivel encontrado: " << level << "]" << std::endl;
				
				// Descomenta y arregla esta línea:
				// (this->*methods[i])();
				return;
			}
		}
		std::cout << "[Nivel desconocido: " << level << "]" << std::endl;
	}
};

int main()
{
	Harl harl;

	std::cout << "--- Probando Harl ---" << std::endl;
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("INVALID");

	return 0;
}
