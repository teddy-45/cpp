#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    std::vector<int> numbers;
    unsigned int maxSize;

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename T>
    void addRange(T begin, T end) {
        if (numbers.size() + std::distance(begin, end) > maxSize)
            throw std::overflow_error("Span is full!");
        numbers.insert(numbers.end(), begin, end);
    }

    void printNumbers() const;
};

#endif
