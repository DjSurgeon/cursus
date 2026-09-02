#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange {
 private:
  std::map<std::string, float> _database;

  void _loadDatabase(const std::string& dbPath);
  bool _isValidDate(const std::string& date) const;
  bool _isValidExchange(const std::string& rateStr) const;
  bool _isValidInputValue(const std::string& valueStr) const;
  std::string _trim(const std::string& str) const;

 public:
  BitcoinExchange();
  BitcoinExchange(const std::string& dbPath);
  BitcoinExchange(const BitcoinExchange& src);
  BitcoinExchange& operator=(const BitcoinExchange& rhs);
  ~BitcoinExchange();

  void processInput(const std::string& inputPath) const;

  class FileOpenException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class InvalidDatabaseException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif
