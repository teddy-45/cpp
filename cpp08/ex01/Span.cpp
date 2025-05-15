#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        this->numbers = other.numbers;
        this->maxSize = other.maxSize;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() >= maxSize)
        throw std::overflow_error("Span is full!");
    numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size(); i++) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");
    return *std::max_element(numbers.begin(), numbers.end()) - 
           *std::min_element(numbers.begin(), numbers.end());
}

void Span::printNumbers() const {
    std::cout << "Numbers in Span: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}
