#include "AForm.hpp"
#include "Bureaucrat.hpp" 

AForm::AForm() : name(""), isSigned(false), gradeToSign(1), gradeToExecute(1){};


AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {
    isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { 
    return name;
}
bool AForm::getIsSigned() const {
    return isSigned;
}
int AForm::getGradeToSign() const {
    return gradeToSign;
}
int AForm::getGradeToExecute() const {
    return gradeToExecute;
}
const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed.";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low.";
}
void AForm::validateGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}
void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}
std::ostream &operator<<(std::ostream &out, const AForm &form) {
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
