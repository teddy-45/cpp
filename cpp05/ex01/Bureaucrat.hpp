#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
private:
    const std::string name;
    int grade;
    void validateGrade(int grade) const;

public:
    class GradeTooHighException : public std::exception {
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char *what() const throw();
    };

    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form) const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
