#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

void Form::validateGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form: " << form.getName() << " | Signed: ";
    if (form.getIsSigned()) {
        out << "Yes";
    } else {
        out << "No";
    }
    out << " | Grade Required to Sign: " << form.getGradeToSign()
        << " | Grade Required to Execute: " << form.getGradeToExecute();
    return out;
}

