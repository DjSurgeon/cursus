/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:03:05 by sergio            #+#    #+#             */
/*   Updated: 2026/02/02 20:04:02 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	void		complain(std::string level);
private:
	void		debug(void);
	void		info(void);
	void		warning(void);
	void		error(void);
};

#endif