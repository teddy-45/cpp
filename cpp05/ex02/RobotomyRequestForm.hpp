#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
private:
    std::string target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    void execute(const Bureaucrat &executor) const;
    ~RobotomyRequestForm();
};


#endif
