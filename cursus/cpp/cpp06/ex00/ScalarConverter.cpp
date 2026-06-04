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

void ScalarConverter::printChar(char c, double valueAsDouble, bool isSpecial) {
    std::cout << "char: ";
    if (isSpecial || valueAsDouble < CHAR_MIN || valueAsDouble > CHAR_MAX || std::isnan(valueAsDouble)) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(c)) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << c << "'" << std::endl;
    }
}

void ScalarConverter::printInt(int i, double valueAsDouble, bool isSpecial) {
    std::cout << "int: ";
    if (isSpecial || valueAsDouble < INT_MIN || valueAsDouble > INT_MAX || std::isnan(valueAsDouble)) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << i << std::endl;
    }
}

void ScalarConverter::printFloat(float f, double valueAsDouble) {
    std::cout << "float: ";
    if (std::isnan(valueAsDouble)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(valueAsDouble)) {
        std::cout << (valueAsDouble > 0 ? "+inff" : "-inff") << std::endl;
    } else {
        if (valueAsDouble == static_cast<long long>(valueAsDouble)) {
            std::cout << std::fixed << std::setprecision(1);
        } else {
            std::cout.unsetf(std::ios_base::floatfield);
        }
        std::cout << f << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: ";
    if (std::isnan(d)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(d)) {
        std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
    } else {
        if (d == static_cast<long long>(d)) {
            std::cout << std::fixed << std::setprecision(1);
        } else {
            std::cout.unsetf(std::ios_base::floatfield);
        }
        std::cout << d << std::endl;
    }
}

void ScalarConverter::convertFromChar(const std::string& literal) {
    char c = literal[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    double valueAsDouble = static_cast<double>(c);

    printChar(c, valueAsDouble, false);
    printInt(i, valueAsDouble, false);
    printFloat(f, valueAsDouble);
    printDouble(d);
}

void ScalarConverter::convertFromInt(const std::string& literal) {
    long val = std::strtol(literal.c_str(), NULL, 10);
    
    int i = static_cast<int>(val);
    char c = static_cast<char>(i);
    float f = static_cast<float>(val);
    double d = static_cast<double>(val);
    double valueAsDouble = static_cast<double>(val);

    printChar(c, valueAsDouble, false);
    printInt(i, valueAsDouble, false);
    printFloat(f, valueAsDouble);
    printDouble(d);
}

void ScalarConverter::convertFromFloat(const std::string& literal) {
    float f = static_cast<float>(std::strtod(literal.c_str(), NULL));
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);
    double valueAsDouble = std::strtod(literal.c_str(), NULL);

    printChar(c, valueAsDouble, false);
    printInt(i, valueAsDouble, false);
    printFloat(f, valueAsDouble);
    printDouble(d);
}

void ScalarConverter::convertFromDouble(const std::string& literal) {
    double d = std::strtod(literal.c_str(), NULL);
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    double valueAsDouble = d;

    printChar(c, valueAsDouble, false);
    printInt(i, valueAsDouble, false);
    printFloat(f, valueAsDouble);
    printDouble(d);
}

void ScalarConverter::convertFromSpecial(const std::string& literal) {
    double d = std::strtod(literal.c_str(), NULL);
    if (literal == "nan" || literal == "nanf") d = std::numeric_limits<double>::quiet_NaN();
    
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    double valueAsDouble = d;

    printChar(c, valueAsDouble, true);
    printInt(i, valueAsDouble, true);
    printFloat(f, valueAsDouble);
    printDouble(d);
}

void ScalarConverter::convert(const std::string& literal) {
    e_type type = identifyType(literal);

    switch (type) {
        case TYPE_CHAR:    convertFromChar(literal); break;
        case TYPE_INT:     convertFromInt(literal); break;
        case TYPE_FLOAT:   convertFromFloat(literal); break;
        case TYPE_DOUBLE:  convertFromDouble(literal); break;
        case TYPE_SPECIAL: convertFromSpecial(literal); break;
        case TYPE_INVALID:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}
