/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:29:40 by sergio            #+#    #+#             */
/*   Updated: 2026/01/10 00:36:38 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Contact          // ← 1. Nombre de la clase
{
private:               // ← 2. Sección PRIVADA
	/* data */
	
public:                // ← 3. Sección PÚBLICA
	Contact(/* args */);   // ← 4. Constructor
	~Contact();            // ← 5. Destructor
};                     // ← 6. ¡Punto y coma obligatorio!

Contact::Contact(/* args */)  // ← 7. Implementación del constructor
{
}

Contact::~Contact()           // ← 8. Implementación del destructor
{
}