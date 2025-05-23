#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
#include <exception>

class AForm;
class Bureaucrat {
private:
    const std::string name;
    int grade;
    void validateGrade(int grade) const;
    Bureaucrat();
public:

    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    class GradeTooHighException : public std::exception {
        const char *what() const throw(); 
    };

    class GradeTooLowException : public std::exception {
        const char *what() const throw();
    };

    std::string getName() const;
    int getGrade() const;

    void signForm(AForm &form) const;
    void executeForm(const AForm &form) const;
    void incrementGrade();
    void decrementGrade();

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
