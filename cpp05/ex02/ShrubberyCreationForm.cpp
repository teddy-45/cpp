#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() >  this->getGradeToExecute())
    {
        throw GradeTooLowException();
    }
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file) {
        std::cout << "Error: Unable to create " << target << "_shrubbery file.\n";
        return;
    }
    file << "        *\n";
    file << "       ***\n";
    file << "      *****\n";
    file << "     *******\n";
    file << "    *********\n";
    file << "   ***********\n";
    file << "       |||\n";
    file.close();
}
