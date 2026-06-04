#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <iomanip>
# include <cmath>
# include <limits>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    enum e_type {
        TYPE_CHAR,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_SPECIAL,
        TYPE_INVALID
    };

    static e_type identifyType(const std::string& literal);
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    static bool isSpecial(const std::string& literal);

    static void printChar(char c, double valueAsDouble, bool isSpecial);
    static void printInt(int i, double valueAsDouble, bool isSpecial);
    static void printFloat(float f, double valueAsDouble);
    static void printDouble(double d);

    static void convertFromChar(const std::string& literal);
    static void convertFromInt(const std::string& literal);
    static void convertFromFloat(const std::string& literal);
    static void convertFromDouble(const std::string& literal);
    static void convertFromSpecial(const std::string& literal);
};

#endif
