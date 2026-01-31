/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:35:27 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 16:44:57 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>

/// @brief Handles the logic for opening files and replacing substrings without std::string::replace.
class FileReplacer
{
public:
	FileReplacer(	const std::string& filename,
					const std::string& str1,
					const std::string& str2);
	~FileReplacer();
	bool				executeReplace();
private:
	const std::string	_infile;
	const std::string	_s1;
	const std::string	_s2;
	const std::string	_outfile;
	bool				_isValidInput();
	const std::string	_readFile(const std::ifstream& infile);
	std::string			_replaceString(std::string buffer);
};

#endif