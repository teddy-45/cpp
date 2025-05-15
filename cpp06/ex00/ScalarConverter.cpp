#include "ScalarConverter.hpp"
#include <cstdlib> 
#include <cctype> 

bool isChar(const std::string &literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool isInt(const std::string &literal) {
    for (size_t i = (literal[0] == '-' || literal[0] == '+') ? 1 : 0; i < literal.length(); ++i) {
        if (!isdigit(literal[i])) return false;
    }
    return true;
}

bool isFloat(const std::string &literal) {
    return literal.find('f') != std::string::npos;
}

bool isDouble(const std::string &literal) {
    return literal.find('.') != std::string::npos && !isFloat(literal);
}

void ScalarConverter::convert(const std::string &literal) {
    char c;
    int i;
    float f;
    double d;


    if (isChar(literal)) {
        c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    } else if (isInt(literal)) {
        char *end;
        long val = std::strtol(literal.c_str(), &end, 10);
        if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min()) {
            std::cout << "Conversion impossible (out of int range)" << std::endl;
            return;
        }
        i = static_cast<int>(val);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);

        if (i >= 32 && i <= 126)
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    } else if (isFloat(literal)) {
        char *end;
        f = std::strtof(literal.c_str(), &end);
        i = static_cast<int>(f);
        c = static_cast<char>(i);
        d = static_cast<double>(f);

        if (i >= 32 && i <= 126)
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    } else if (isDouble(literal)) {
        char *end;
        d = std::strtod(literal.c_str(), &end);
        i = static_cast<int>(d);
        c = static_cast<char>(i);
        f = static_cast<float>(d);

        if (i >= 32 && i <= 126)
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    } else if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
    } else if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    } else {
        std::cout << "Conversion impossible" << std::endl;
    }
}
