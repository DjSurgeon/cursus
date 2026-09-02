#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
 private:
  std::stack<int> _stack;

  bool _isOperator(const std::string& token) const;
  bool _isNumber(const std::string& token) const;
  void _executeOperation(const std::string& op);

 public:
  RPN();
  RPN(const RPN& src);
  RPN& operator=(const RPN& rhs);
  ~RPN();

  void calculate(const std::string& expression);

  class ErrorException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif
