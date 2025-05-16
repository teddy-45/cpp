#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() >  this->getGradeToExecute())
    {
        throw GradeTooLowException();
    }
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}