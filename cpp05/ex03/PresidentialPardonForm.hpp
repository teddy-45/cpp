// #ifndef PRESIDENTIALPARDONFORM_HPP
// #define PRESIDENTIALPARDONFORM_HPP
#pragma once
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
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();
    
    void execute(const Bureaucrat &executor) const;
};
