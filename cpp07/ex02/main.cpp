#include "Array.hpp"

int main() {
    try {
        std::cout << "--- Test 1: Default constructor ---\n";
        Array<int> a1;
        std::cout << "Size: " << a1.size() << "\n";

        std::cout << "\n--- Test 2: Constructor with size ---\n";
        Array<int> a2(5);
        std::cout << "Size: " << a2.size() << "\n";
        for (unsigned int i = 0; i < a2.size(); ++i) {
            a2[i] = i * 10;
            std::cout << "a2[" << i << "] = " << a2[i] << "\n";
        }

        std::cout << "\n--- Test 3: Copy constructor ---\n";
        Array<int> a3(a2);
        a3[0] = 999;
        std::cout << "a2[0] = " << a2[0] << std::endl;
        std::cout << "a3[0] = " << a3[0] << std::endl;

        std::cout << "\n--- Test 4: Assignment operator ---\n";
        Array<int> a4;
        a4 = a2;
        a4[1] = 888;
        std::cout << "a2[1] = " << a2[1] << std::endl;
        std::cout << "a4[1] = " << a4[1] << std::endl;

        std::cout << "\n--- Test 5: Out of bounds ---\n";
        std::cout << a2[10] << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exp: " << e.what() << std::endl;
    }


    try {
        Array<char> char1(5);
        std::cout << "Size: " << char1.size() << "\n";
        for (unsigned int i = 0; i < char1.size(); i++) {
            char1[i] = 'a';
        std::cout << char1[i] << std::endl;
        }
        char1[10] = 'b';
    }
    catch (const std::exception &e) {
        std::cout << "Exp: " << e.what() << std::endl;
    }
    try {
        Array<std::string> str(2);
        str[0] = "hello ";
        str[1] = "teddy\n";
        std::cout << str[0] << str[1];
        std::cout << str[3];
    }
    catch (const std::exception &e) {
        std::cout << "Exp: " << e.what() << std::endl;
    }
    return 0;
}
