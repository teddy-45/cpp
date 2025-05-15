#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
    try {
        int arr1[] = {10, 20, 30, 40, 50};
        std::vector<int> vec(arr1, arr1 + 5);

        std::cout << "Found in vector: " << *easyfind(vec, 30) << std::endl;
        std::cout << "Found in vector: " << *easyfind(vec, 50) << std::endl;

        int arr2[] = {5, 15, 25, 35, 45};
        std::list<int> lst(arr2, arr2 + 5);
        std::cout << "Found in list: " << *easyfind(lst, 15) << std::endl;

        int arr3[] = {100, 200, 300, 400, 500};
        std::deque<int> deq(arr3, arr3 + 5);
        std::cout << "Found in deque: " << *easyfind(deq, 500) << std::endl;

        std::cout << "Searching for 99 in vector..." << std::endl;
        std::cout << *easyfind(vec, 99) << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
