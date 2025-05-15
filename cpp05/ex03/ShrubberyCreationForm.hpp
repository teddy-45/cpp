#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    std::string target;
    void executeAction() const;

public:
    ShrubberyCreationForm(const std::string &target);
    ~ShrubberyCreationForm();
};

#endif
