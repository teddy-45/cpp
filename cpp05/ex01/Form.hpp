#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

    void validateGrade(int grade) const;

public:
    class GradeTooHighException : public std::exception {
        const char *what() const throw() {
            return "Form grade is too high.";
        }
    };

    class GradeTooLowException : public std::exception {
        const char *what() const throw() {
            return "Form grade is too low.";
        }
    };

    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
