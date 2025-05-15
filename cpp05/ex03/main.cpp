#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;
    AForm *form;
    ShrubberyCreationForm a("teddy");

    form = intern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = intern.makeForm("shrubbery creation", "Garden");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = intern.makeForm("presidential pardon", "Morty");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = intern.makeForm("invalid form", "Nobody");
    if (form) {
        delete form;
    }
    
    return 0;
}
