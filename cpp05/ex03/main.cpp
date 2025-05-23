#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {

 try {
        Bureaucrat highRank("Alice", 149);
        // Bureaucrat lowRank("Bob", 150);

        ShrubberyCreationForm shrubForm("Garden");
        PresidentialPardonForm pardonForm("Criminal");
        RobotomyRequestForm robotForm("Subject");

        std::cout << highRank << std::endl;
        // std::cout << lowRank << std::endl;

        highRank.signForm(shrubForm);
        highRank.executeForm(shrubForm);

        // highRank.signForm(pardonForm);
        // highRank.executeForm(pardonForm);

        // highRank.signForm(robotForm);
        // highRank.executeForm(robotForm);

        // lowRank.signForm(shrubForm);
        // lowRank.executeForm(shrubForm);

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
