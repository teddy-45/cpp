#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
    std::cout << " *Drilling noises *\n";
    if (std::rand() % 2 == 0) {
        std::cout << target << " has been successfully robotomized!\n";
    } else {
        std::cout << "Robotomy failed on " << target << "!\n";
    }
}
