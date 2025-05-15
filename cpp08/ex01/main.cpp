#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::vector<int> bigNumbers;
        for (int i = 1; i <= 10000; i++) {
            bigNumbers.push_back(i);
        }

        Span bigSpan(10000);
        bigSpan.addRange(bigNumbers.begin(), bigNumbers.end());

        std::cout << "Big Span - Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big Span - Longest: " << bigSpan.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
