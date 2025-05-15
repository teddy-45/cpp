#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
private:
    std::string target;
    void executeAction() const;

public:
    PresidentialPardonForm(const std::string &target);
    ~PresidentialPardonForm();
};

#endif
