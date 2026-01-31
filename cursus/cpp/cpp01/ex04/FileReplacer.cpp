/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:35:28 by sergio            #+#    #+#             */
/*   Updated: 2026/01/31 16:48:53 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

/// @brief Constructor. Initializes file paths and replacement strings.
/// @param filename Path to the input file.
/// @param str1 The string to search for.
/// @param str2 The string to replace with.
FileReplacer::FileReplacer(const std::string& filename, const std::string& str1, const std::string& str2) : _infile(filename), _s1(str1), _s2(str2), _outfile(filename + ".replace")
{
}

/// @brief Destructor.
FileReplacer::~FileReplacer()
{
}

/// @brief Main entry point. Validates input, opens files, and runs replacement.
/// @return true if successful, false if any error occurred.
bool	FileReplacer::executeReplace()
{
	if (!_isValidInput())
		return (false);
	std::ifstream	infile(_infile.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: unable to open file: " << _infile << std::endl;
		return (false);
	}
	std::string buffer = _readFile(infile);
	infile.close();
	std::string replacedBuffer = _replaceString(buffer);
	std::ofstream outfile(_outfile.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: unable to create output file: " << _outfile << std::endl;
		return (false);
	}
	outfile << replacedBuffer;
	outfile.close();
	return (true);
}

/// @brief Checks if filenames and search strings are valid (not empty).
/// @return true if valid.
bool	FileReplacer::_isValidInput()
{
	if (_infile.empty())
	{
		std::cerr << "Error: Filename cannot be empty" << std::endl;
		return (false);
	}
	if (_s1.empty())
	{
		std::cerr << "Error: string 1 cannot be empty" << std::endl;
		return (false);
	}
	return (true);
}

/// @brief Reads the entire content of a file into a std::string.
/// @param infile Reference to the open input file stream.
/// @return The full content of the file.
const std::string	FileReplacer::_readFile(const std::ifstream& infile)
{
	std::ostringstream buffer;
	buffer << infile.rdbuf();
	return (buffer.str());
}

/// @brief Core algorithm. Replaces all occurrences of _s1 with _s2.
/// @param buffer The original string content.
/// @return The modified string.
std::string	FileReplacer::_replaceString(std::string buffer)
{
	std::string::size_type	position;
	std::string::size_type	len1 = _s1.length();
	position = buffer.find(_s1);
	while (position != std::string::npos)
	{
		if (position == std::string::npos)
			break ;
		buffer.erase(position, len1);
		buffer.insert(position, _s2);
		position += _s2.length();
		position = buffer.find(_s1);
	}
	return (buffer);
}