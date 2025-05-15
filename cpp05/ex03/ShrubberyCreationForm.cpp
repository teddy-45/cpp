#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file) {
        std::cerr << "Error: Unable to create " << target << "_shrubbery file.\n";
        return;
    }
    file << "        🌲\n";
    file << "       🌲🌲\n";
    file << "      🌲🌲🌲\n";
    file << "     🌲🌲🌲🌲\n";
    file << "    🌲🌲🌲🌲🌲\n";
    file << "   🌲🌲🌲🌲🌲🌲\n";
    file.close();
}
