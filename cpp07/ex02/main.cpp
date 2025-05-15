// #include <iostream>
// #include "Array.hpp"

// int main() {
//     try {
//         Array<int> emptyArr;
//         std::cout << "Empty array size: " << emptyArr.size() << std::endl;

//         Array<int> intArr(5);
//         for (unsigned int i = 0; i < intArr.size(); i++)
//             intArr[i] = i  *10;

//         std::cout << "intArr contents: ";
//         for (unsigned int i = 0; i < intArr.size(); i++)
//             std::cout << intArr[i] << " ";
//         std::cout << std::endl;

//         Array<int> copyArr(intArr);
//         std::cout << "Copy intArr: ";
//         for (unsigned int i = 0; i < copyArr.size(); i++)
//             std::cout << copyArr[i] << " ";
//         std::cout << std::endl;

//         intArr[2] = 999;
//         std::cout << "After modifying intArr, copyArr remains unchanged: ";
//         for (unsigned int i = 0; i < copyArr.size(); i++)
//             std::cout << copyArr[i] << " ";
//         std::cout << std::endl;

//         std::cout << "Trying to access index 10..." << std::endl;
//         std::cout << intArr[10] << std::endl;

//     } catch (const std::exception &e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}