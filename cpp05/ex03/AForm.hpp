#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat; 

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

    void validateGrade(int grade) const;

protected:
    virtual void executeAction() const = 0;

public:

AForm(const std::string &name, int gradeToSign, int gradeToExecute);
AForm(const AForm &other);
AForm &operator=(const AForm &other);
virtual ~AForm();

class GradeTooHighException : public std::exception {
    const char *what() const throw() { return "Grade is too high."; }
};

class GradeTooLowException : public std::exception {
    const char *what() const throw() { return "Grade is too low."; }
};

class FormNotSignedException : public std::exception {
    const char *what() const throw() { return "Form is not signed."; }
};

std::string getName() const;
bool getIsSigned() const;
int getGradeToSign() const;
int getGradeToExecute() const;

void beSigned(const Bureaucrat &b);
void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
