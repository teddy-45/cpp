#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
    std::string target;
    void executeAction() const;

public:
    RobotomyRequestForm(const std::string &target);
    ~RobotomyRequestForm();
};

#endif
