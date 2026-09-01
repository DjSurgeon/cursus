#include "RPN.hpp"

// -----------------------------------------------------------------------------
// Constructors and Destructor
// -----------------------------------------------------------------------------

RPN::RPN() {}

RPN::RPN(const RPN& src) {
    *this = src;
}

RPN& RPN::operator=(const RPN& rhs) {
    if (this != &rhs) {
        this->_stack = rhs._stack;
    }
    return *this;
}

RPN::~RPN() {}

// -----------------------------------------------------------------------------
// Exceptions
// -----------------------------------------------------------------------------

const char* RPN::ErrorException::what() const throw() {
    return "Error";
}

// -----------------------------------------------------------------------------
// Private Helpers
// -----------------------------------------------------------------------------

bool RPN::_isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::_isNumber(const std::string& token) const {
    if (token.length() != 1) return false;
    return isdigit(token[0]);
}

void RPN::_executeOperation(const std::string& op) {
    if (_stack.size() < 2) {
        throw ErrorException();
    }

    int right = _stack.top();
    _stack.pop();
    
    int left = _stack.top();
    _stack.pop();

    int result = 0;

    if (op == "+") {
        result = left + right;
    } else if (op == "-") {
        result = left - right;
    } else if (op == "*") {
        result = left * right;
    } else if (op == "/") {
        if (right == 0) {
            throw ErrorException();
        }
        result = left / right;
    }

    _stack.push(result);
}

// -----------------------------------------------------------------------------
// Logic
// -----------------------------------------------------------------------------

void RPN::calculate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (_isNumber(token)) {
            _stack.push(std::atoi(token.c_str()));
        } 
        else if (_isOperator(token)) {
            _executeOperation(token);
        } 
        else {
            throw ErrorException();
        }
    }

    if (_stack.size() != 1) {
        throw ErrorException();
    }

    std::cout << _stack.top() << std::endl;
}
