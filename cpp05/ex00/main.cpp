#include "Bureaucrat.hpp"

void foo (int i){
    if (i < 0)
        throw 42;
}

int main() {
    try {
        // Bureaucrat bob("Bob", 151);
        // std::cout << bob << std::endl;

        // bob.incrementGrade();
        // std::cout << "After incrementing: " << bob << std::endl;

        // bob.decrementGrade();
        // bob.decrementGrade();
        // std::cout << "After decrementing: " << bob << std::endl;

        // Bureaucrat alice("Alice", 0);
        // std::cout << alice << std::endl;
        foo(-1);
        // alice.decrementGrade(); 
    // } catch (const std::exception &e) {
    //     std::cerr << "Exception1: " << e.what() << std::endl;
    // }
    }
    catch ( ... ) {
        std::cerr << "Exception1:  "  << std::endl;
    }

    try {
        // Bureaucrat high("High", 1); 
        // high.decrementGrade();
        // std::cout << high << "\n";
    } catch (const std::exception &e) {
        // std::cerr << "Exception2: " << e.what() << std::endl;
    }

    return 0;
}
