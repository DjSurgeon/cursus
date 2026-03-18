/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespaces.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:42:49 by sergio            #+#    #+#             */
/*   Updated: 2026/01/09 23:47:16 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Definir tu propio namespace
namespace mylib {
    void foo() {
        std::cout << "foo from MyLib" << std::endl;
    }
}

// Usar tu namespace
int main() {
	std::string str("Hi");
    mylib::foo();           // Llamada explícita
    std::cout << str;      // Siempre explícito con std
    return 0;
}