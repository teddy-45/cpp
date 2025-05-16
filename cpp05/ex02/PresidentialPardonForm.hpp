#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;
class PresidentialPardonForm : public AForm {
private:
    std::string target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    void execute(const Bureaucrat &executor) const;
    ~PresidentialPardonForm();
};

#endif
