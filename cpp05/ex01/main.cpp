#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 5);
        Bureaucrat bob("Bob", 999);

        Form taxForm("Tax Form", 10, 50);

        std::cout << taxForm << std::endl;
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
