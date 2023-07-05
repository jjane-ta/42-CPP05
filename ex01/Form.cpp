#include "Form.hpp"


// OCCP
Form::Form ( std::string name, int grade ):
    _name(name),
    _grade(grade),
    _is_signed(false)
{
    if (this->_grade > this->_minGrade)
        throw Form::GradeTooLowException();
    if (this->_grade < this->_maxGrade)
        throw Form::GradeTooHighException();
}

Form::~Form ( void )
{}

Form::Form (const Form &form):
    _name(form._name),
    _grade(form._grade),
    _is_signed(false)
{}

Form Form::operator = (const Form &form){
    return Form(form.getName(), form.getGrade());
}

const std::string Form::getName ( void ) const{
    return (this->_name);
}

int Form::getGrade ( void ) const{
    return (this->_grade);
}

bool Form::isSigned ( void ){
    return (this->_is_signed);
}

void Form::beSigned ( const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > this->_grade){
        throw Form::GradeTooLowException();
    } else {
        this->_is_signed = true;
    }
}

// Exceptions
Form::GradeTooHighException::GradeTooHighException() :
    std::runtime_error("\033[1;31mstd::exception => Form::GradeTooHighException\033[0m\n"){}

Form::GradeTooLowException::GradeTooLowException() : 
    std::runtime_error("\033[1;31mstd::exception => Form::GradeTooLowException\033[0m\n"){}

// Overload stream output
std::ostream &operator<<(std::ostream &os, Form &form)
{
    if (form.getName().size()) {
        os << "\033[1;34m" << form.getName() << ", form grade " << form.getGrade();
    } else {
        os << "\033[1;34m" << "TOP-SECRET" << ", form grade " << form.getGrade();
    }
    if (form.isSigned()) {
        os << " is signed.\033[0m\n";
    } else {
        os << " is not signed.\033[0m\n";
    }
    return os;
}