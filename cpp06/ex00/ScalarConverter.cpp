#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void    printCases(const std::string &str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
    if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
	else if (str == "nan" || str == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "-inf" || str == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else {
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}


static bool isChar(const std::string &s) {
    return (s.length() == 1 && isprint(s[0]) && !isdigit(s[0]));
}

static bool isInt(const std::string &s) {
    int i = 0;
    if (s[i] == '-' || s[i] == '+')
        i++;
    if (i == (int)s.length())
        return false;
    for (int j = i; j < (int)s.length(); j++)
        if (!isdigit(s[j]))
            return false;
    return true;
}

static bool isFloat(const std::string &s) {
    int dot = 0, digit = 0;
    int i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    for (int j = i; j < (int)s.length() - 1; j++) {
        if (s[j] == '.')
            dot++;
        else if (isdigit(s[j]))
            digit++;
        else
            return false;
    }
    return s[s.length() - 1] == 'f' && dot <= 1 && digit > 0;
}

static bool isDouble(const std::string &s) {
    int dot = 0, digit = 0;
    int i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    for (int j = i; j < (int)s.length(); j++) {
        if (s[j] == '.')
            dot++;
        else if (isdigit(s[j]))
            digit++;
        else
            return false;
    }
    return dot == 1 && digit > 0;
}


void ScalarConverter::convert(const std::string &literal) {
    if (isChar(literal)) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    else if (isInt(literal)) {
        int i = std::atoi(literal.c_str());
        if (i >= 32 && i <= 126)
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    }
    else if (isFloat(literal)) {
        float f = std::atof(literal.c_str());
        if (f >= 32 && f <= 126)
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (f <= INT_MAX && f >= INT_MIN)
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else if (isDouble(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        if (d >= 32 && d <= 126 )
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (d <= INT_MAX && d >= INT_MIN)
        std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        if (d <= FLT_MAX && d >= -FLT_MAX)
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        else
            std::cout << "float: impossible" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else {
        printCases(literal);
    }
}
