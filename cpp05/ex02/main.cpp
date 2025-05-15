#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 50);
        Bureaucrat tom("Tom", 140);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n--- Bureaucrats and Forms Created ---\n";

        std::cout << "\n[ Shrubbery Form Test ]\n";
        tom.signForm(shrubbery);
        tom.executeForm(shrubbery); 
        bob.executeForm(shrubbery); 

        std::cout << "\n[ Robotomy Form Test ]\n";
        alice.signForm(robotomy);
        alice.executeForm(robotomy); 

        std::cout << "\n[ Pardon Form Test ]\n";
        bob.signForm(pardon);
        bob.executeForm(pardon); 

    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
