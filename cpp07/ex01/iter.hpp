#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <exception>

// template <typename T>
void printElement(const T &elem) {
    std::cout << elem << " ";
}

template <typename T, typename F>
void iter(T *array, size_t length, F func) {
    if(!array)
        return ;
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif
