#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
private:
    std::string target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    void execute(const Bureaucrat &executor) const;
    ~ShrubberyCreationForm();
};

#endif
