#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal) {
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+') i++;
    if (i == literal.length()) return false;
    for (; i < literal.length(); i++) {
        if (!std::isdigit(literal[i])) return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") return true;
    if (literal[literal.length() - 1] != 'f') return false;
    
    bool foundDot = false;
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+') i++;
    for (; i < literal.length() - 1; i++) {
        if (literal[i] == '.') {
            if (foundDot) return false;
            foundDot = true;
        } else if (!std::isdigit(literal[i])) return false;
    }
    return foundDot;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf") return true;
    
    bool foundDot = false;
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+') i++;
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (foundDot) return false;
            foundDot = true;
        } else if (!std::isdigit(literal[i])) return false;
    }
    return foundDot;
}

bool ScalarConverter::isSpecial(const std::string& literal) {
    return (literal == "nan" || literal == "nanf" || 
            literal == "+inf" || literal == "-inf" || 
            literal == "+inff" || literal == "-inff");
}

ScalarConverter::e_type ScalarConverter::identifyType(const std::string& literal) {
    if (isSpecial(literal)) return TYPE_SPECIAL;
    if (isChar(literal)) return TYPE_CHAR;
    if (isInt(literal)) return TYPE_INT;
    if (isFloat(literal)) return TYPE_FLOAT;
    if (isDouble(literal)) return TYPE_DOUBLE;
    return TYPE_INVALID;
}

void ScalarConverter::printChar(double d, bool isSpecial) {
    std::cout << "char: ";
    if (isSpecial || d < CHAR_MIN || d > CHAR_MAX || std::isnan(d)) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(d))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double d, bool isSpecial) {
    std::cout << "int: ";
    if (isSpecial || d < INT_MIN || d > INT_MAX || std::isnan(d)) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }
}

void ScalarConverter::printFloat(double d) {
    std::cout << "float: ";
    if (std::isnan(d)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(d)) {
        std::cout << (d > 0 ? "+inff" : "-inff") << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: ";
    if (std::isnan(d)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(d)) {
        std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    e_type type = identifyType(literal);
    double d = 0;

    if (type == TYPE_INVALID) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (type == TYPE_CHAR) {
        d = static_cast<double>(literal[0]);
    } else {
        d = std::strtod(literal.c_str(), NULL);
    }

    printChar(d, type == TYPE_SPECIAL);
    printInt(d, type == TYPE_SPECIAL);
    printFloat(d);
    printDouble(d);
}
