#include "RobotomyRequestForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;
RobotomyRequestForm::RobotomyRequestForm() : AForm("obotomyRequestForm", 72, 45), target("target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::srand(std::time(0));

}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 72, 45), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    this->target = other.target;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() >  this->getGradeToExecute())
    {
        throw GradeTooLowException();
    }
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    std::cout << " *Drilling noises *\n";
    if (std::rand() % 2 == 0) {
        std::cout << target << " has been successfully robotomized!\n";
    } else {
        std::cout << "Robotomy failed on " << target << "!\n";
    }
}
