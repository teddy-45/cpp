#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    this->grade = other.grade;
    return *this;
}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
    validateGrade(grade);
    this->grade = grade;
}
Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
    return name;
}
int Bureaucrat::getGrade() const {
    return grade;
}
void Bureaucrat::incrementGrade() {
    validateGrade(grade - 1);
    grade--;
}
void Bureaucrat::decrementGrade() {
    validateGrade(grade + 1);
    grade++;
}
void Bureaucrat::validateGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high.";
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low.";
}
void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
void Bureaucrat::executeForm(const AForm &form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
