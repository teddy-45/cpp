#include <iostream>
#include "iter.hpp"

int main() {
    try {
        int intArray[] = {1, 2, 3, 4, 5};
        std::string strArray[] = {"Hello", "World", "42", "teddy"};
    
        std::cout << "Integer Array: ";
        iter((int *)NULL, 5, printElement<int>);
        iter(intArray, 5, printElement<int>);
        std::cout << std::endl;
    
        std::cout << "String Array: ";
        iter(strArray, 4, printElement<std::string>);
        std::cout << std::endl;
    }
    catch(std::exception &e) {
        std::cout << "exp : " << e.what() << std::endl;
    }

    return 0;
}

