#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 70);

        Form taxForm("Tax Form", 10, 10);

        std::cout << taxForm << std::endl;
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;
        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;


    } catch (std::exception &exp) {
        std::cerr << "Exception: " << exp.what() << std::endl;
    }
    return 0;
}
